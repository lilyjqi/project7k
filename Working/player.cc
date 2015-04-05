#include "player.h"
#include "building.h"
#include "gameBoard.h"
#include "acadBuilding.h"
#include "osap.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Player::Player(string name, char c, int position, int rindex, int cindex): 
    Owner(name), character(c), position(position), rindex(rindex), cindex(cindex), rollDoubleFailCount(0),
    landed(true) {gb = GameBoard::getInstance(School::getInstance(), BoardDisplay::getInstance(), rollUpRim::getInstance());}

int Player::getRow() {
    return rindex;
}

int Player::getCol() {
    return cindex;
}

// string Player::getName() {
//     return name;
// }

char Player::getChar() {
    return character;
}

int Player::getWorth() {
    int w=balance;
    for (int i=0; i<numBuilding; i++) {
        Building *pbd = dynamic_cast<Building *>(ownBuilding[i]);
        if (pbd) { w += pbd->getCost(); }
    }
    return w;
}

void Player::setLanded(bool isLanded) {landed = isLanded;}
bool Player::getLanded() const {return landed;}

void Player::updateBuilding(Tile *newAb) {
    for (int i=0; i<numBuilding; ++i) {
        if (ownBuilding[i]->getIndex() == newAb->getIndex()) {
            ownBuilding[i] = newAb;
            break;
        }
    }
}

bool Player::isDouble() {
    srand(time(NULL));
    int dice1 = rand()%6+1;
    int dice2 = rand()%6+1;
    cout << "Player " << name << " rolled " << dice1 << " and " << dice2 << endl;
    if (dice1 == dice2) {
        cout << "Get out of Tims Line!";
        return true;
    }
    cout << "Fail!" << endl;
    return false;
}

int Player::getRollDoubleFailCount(){ return rollDoubleFailCount; }
void Player::setRollDoubleFailCount(int n) { rollDoubleFailCount=n; }

int Player::rollDice() {
    for (int i=0; i<3; ++i) {
        srand(time(NULL));
        int dice1 = rand()%6+1;
        int dice2 = rand()%6+1;
        cout << "Player " << name << " rolled" << dice1+dice2 << endl;

        // if didn't roll doubles
        if (dice1 != dice2) {  
            return dice1 + dice2;
        }

        cout << "Doubles! Roll again!" << endl;
    }
    return -1;
}

void Player::makeMove(int m) {
            
        // devisit previous tile
        gb->getTile(position)->devisit(this);
        
        int newpos = position + m;
        // collectOSAP if pass by
        if (newpos > 40) {
            newpos -= 40;
            Osap *osap = dynamic_cast<Osap *>(gb->getTile(0));
            this->addBalance(osap->collectOSAP());
        }
        else if (newpos == 40) {newpos = 0;}

        // move to new pos and take action
        Tile * t = gb->getTile(newpos);
        position = newpos;
        rindex = t->getRindex();
        cindex = t->getCindex();
            
        Building *build = dynamic_cast<Building *>(t);
        School *school = School::getInstance();
        // if move to an ownable building
        if (build) {
            
            t->visit(this);
            notifyDisplay(t);
            // if building is owned by someone
            if (build->getOwner()!=school) {

                // if current player is the owner of t
                if (build->getOwner() == this) {
                         
                    AcadBuilding *aBuild = dynamic_cast<AcadBuilding *>(t);
                    // if t is an academic building
                    if (aBuild) {
                        // if t is in a monopoly
                        if (aBuild->isMono()) {
                            int c = aBuild->getImprCost();
                            cout << "Cost of improvement is " << c << endl;
                            cout << "Do you want to make improvement to your building?(y/n)" << endl;
                            string decision = "";
                            while (cin >> decision) {

                                // make improvement
                                if (decision == "y") {
                                    if (c > this->getBalance()) {
                                        this->noMoney();
                                        if (this->getBalance() == -1) {return;}
                                        this->addBalance(-c);
                                        aBuild->improv();
                                        break;
                                    }
                                    else {
                                        this->addBalance(-c);
                                        aBuild->improv();
                                        break;
                                    }
                                }

                                // do nothing
                                else if (decision == "n") {
                                    break;
                                }
                                else {
                                    cout << "Please enter (y) or (n)." << endl;
                                }
                            }// while
                        }// if t is in a monopoly

                        // if t is not in a monopoly
                        else {
                            cout << "This is your building!" << endl;
                        }// else t is not in a monopoly
                    }//if t is an academic building

                    else {
                        cout << "This is your building~" << endl;
                    }// if t is not an academic building
                }// if current player is the owner of t

                // if current player is not the owner of t
                else {
                    string ownerName = build->getOwner()->getName();
                    int payAmount = 0;
                    AcadBuilding *Abuild = dynamic_cast<AcadBuilding *>(t);
                    

                    // if t is an academic building
                    if (Abuild) {

                        if (Abuild->isMort()) {
                            cout << "This builiding is on mortgage. You don't need to pay!" << endl;
                            return;
                        }

                        // if t is in a monopoly
                        if (Abuild->isMono()) {
                            if (Abuild->getCurLevel() == 0) {payAmount = (Abuild->getPay()) * 2;}
                            else {payAmount = Abuild->getPay();}
                        }

                        // if t is not in a monopoly
                        else {
                            payAmount = Abuild->getPay();
                        }
                    }// if t is an academic building

                    // if t is not an academic building
                    else {
                        payAmount = Abuild->getPay();
                    }
          
                    cout << "You have entered " << ownerName << "'s Building." << endl;
                    cout << "Please pay " << payAmount << endl;

                    if (payAmount > this->getBalance()) {
                        this->noMoney(Abuild->getOwner());
                        if (this->getBalance() == -1) {return;}
                        cout << "You have paid " << payAmount << " dollars to " << ownerName << endl;
                        this->addBalance(-payAmount);
                        Abuild->getOwner()->addBalance(payAmount);
                    }
                    else {
                        cout << "You have paid " << payAmount << " dollars to " << ownerName << endl;
                        this->addBalance(-payAmount);
                        Abuild->getOwner()->addBalance(payAmount);
                    }
                }// else current player is not the owner of t
            }//if building is owned

            // if building is not owned by anyone
            else {
                int c = build->getCost();
                string n = build->getName();
                cout << "Cost of " << n << "is " << c << endl;
                cout << "Do you want to buy it?(y/n)" << endl;
                string decision="";
                while (cin >> decision) {
                    if (decision == "y") {
                        if (c > this->getBalance()) {
                            this->noMoney();
                            if (this->getBalance() == -1) {return;}
                            this->addBalance(-c);
                            this->addBuilding(t);
                            school->deleteBuilding(t);
                            break;
                        }
                        else {
                            this->addBalance(-c);
                            this->addBuilding(t);
                            school->deleteBuilding(t);
                            break;
                        }
                    }
                    else if (decision == "n") {
                        //t->auction();
                        break;
                    }
                    else {
                        cout << "Please enter (y) or (n)." << endl;
                    }
                }// while
            }// if building is not owned by anyone
        }// if moved to an ownable building

        // if moved to an unownable building
        else {
            this->setLanded(true);
            notifyDisplay(t);
            notify(t);
            return;
        }// if moved to an unownable building
}

void Player::notify(Tile * t) {
    t->action(this);
}

void Player::notifyDisplay(Tile *t) {
    gb->getDisplay()->updatePos(t);
}

void Player::goToIndex(int index) {
    Tile *t = gb->getTile(index);
    notify(t);
    notifyDisplay(t);
    position = index;
    rindex = t->getRindex();
    cindex = t->getCindex();
}

void Player::threeOptions(string com) {
    istringstream iss(com); 
    string c = "";
    iss >> c;
    if (c == "trade") {
        this->makeTrade(com);
    }
    else if (c == "improve") {
        this->makeImprove(com);   
    }
    else {
        this->makeMortgage(com);
    }
}

void Player::noMoney() {
    cout << "You don't have enough money." << endl;
    cout << "You have five options." << endl;
    cout << "asset/bankrupt/Trade/Mortgage/Sell Improvements" << endl;
    cout << "Please enter <enough> to continue making improvements!" << endl;
    
    School *school = School::getInstance();
    string command = "";
    while (getline(cin, command)) {
        if (command == "enough") {break;}

        else if (command == "bankrupt") {
            // buildings goes to auction
            for (int i=0; i<numBuilding; ++i) {
                //ownBuilding[i]->auction();
                this->deleteBuilding(ownBuilding[i]);
            }
            // destroy rim cups
            for (int i=0; i<4; ++i) {
                if (gb->cups[i]->getOwner() == this) {gb->cups[i]->setOwner(school);}
            }
            
            this->addBalance(-1-(this->getBalance()));
            return;
        }
        
        else if (command == "asset") {
            this->asset();
        }
        
        else {
            this->threeOptions(command);
            cout << "You now have " << this->getBalance() << endl;
        }
    }
}

void Player::noMoney(Owner *owes) {
    cout << "You don't have enough money." << endl;
    cout << "You have five options." << endl;
    cout << "asset/bankrupt/Trade/Mortgage/Sell Improvements" << endl;
    cout << "Please enter <enough> to continue making improvements!" << endl;
    
    School *school = School::getInstance();
    string command = "";
    while (getline(cin, command)) {
        if (command == "enough") {break;}

        else if (command == "bankrupt") {
            for (int i=0; i<numBuilding; ++i) {
                owes->addBuilding(ownBuilding[i]);
                ownBuilding[i]->setOwner(owes);
                
                Building *build = dynamic_cast<Building *>(ownBuilding[i]);
                // if building is on mortgage
                if (build->isMort()) {
                    int principle = build->getMort();
                    owes->addBalance(-0.1*principle);

                    cout << "Do you want to unmortgage now? (y/n)" << endl;
                    string decision = "";
                    while (cin >> decision) {
                        if (decision == "y") {
                            owes->addBalance(-principle);
                            build->setMort(0);
                            break;
                        }
                        else if (decision == "n") {
                            build->setMort(principle*1.1);
                            break;
                        }
                        else {
                            cout << "Please enter <y> or <n>." << endl;
                        }
                    }

                }
                this->deleteBuilding(ownBuilding[i]);
            }
            
            for (int i=0; i<4; ++i) {
                if (gb->cups[i]->getOwner() == this) {gb->cups[i]->setOwner(school);}
            }
            
            this->addBalance(-1-(this->getBalance()));
            return;
        }
        
        else if (command == "asset") {
            this->asset();
        }
        
        else {
            this->threeOptions(command);
            cout << "You now have " << this->getBalance() << endl;
        }
    }
}

void Player::makeTrade(string com) {
    istringstream iss(com); 
    string c = "";
    iss >> c;

    string otherPlayer = "";
    iss >> otherPlayer;
    Player *other = gb->getPlayer(otherPlayer);

    string give = "";
    iss >> give;

    string receive = "";
    iss >> receive;

    cout << "Player " << otherPlayer << ", do you want to make the trade? (y/n)" << endl;
    string decision = "";
    while (cin >> decision) {
        if (decision == "y") {
            istringstream issgive(give);
            int g;

            // if give money, must be receiving a building
            if (!(issgive >> g).fail()) {
                this->addBalance(-g);
                other->addBalance(g);

                Building *receiveBuilding = dynamic_cast<Building *>(gb->getTile(receive));
                receiveBuilding->setOwner(this);
                this->addBuilding(receiveBuilding);
                other->deleteBuilding(receiveBuilding);
            }

            // if give a building
            else {
                istringstream issreceive(receive);
                int r;
                
                Building *giveBuilding = dynamic_cast<Building *>(gb->getTile(give));
                // receive money
                if (!(issreceive >> r).fail()) {
                    this->addBalance(r);
                    other->addBalance(-r);

                    giveBuilding->setOwner(other);
                    this->deleteBuilding(giveBuilding);
                    other->addBuilding(giveBuilding);
                }

                // receive building
                else {
                    Building *receiveBuilding = dynamic_cast<Building *>(gb->getTile(receive));
                    receiveBuilding->setOwner(this);
                    giveBuilding->setOwner(other);

                    this->deleteBuilding(giveBuilding);
                    other->addBuilding(giveBuilding);
                    this->addBuilding(receiveBuilding);
                    other->deleteBuilding(receiveBuilding);
                }
            }// if give a building
            break;
        }// if agree to trade

        else if (decision == "n") {
            cout << "Your offer has been rejected!" << endl;
            break;
        }// if disagree to trade

        else {
            cout << "Please enter (y) or (n)." << endl;
        }
    }// while
}

void Player::makeImprove(string com) {
    istringstream iss(com); 
    string c = "";
    iss >> c;
    
    string property="";
    iss >> property;

    string bors="";
    iss >> bors;
    
    AcadBuilding *p = dynamic_cast<AcadBuilding *>(gb->getTile(property));
    int price = p->getImprCost();

    if (bors == "buy") {
        cout << "Price is " << price << endl;
        if (this->getBalance() < price) {
            cout << "You don't have enough money!" << endl;
        }
        else {
            this->addBalance(-price);
            p->improv();
            cout << "You have improved to Level "<< p->getCurLevel() << endl;
        }
    }
    else {
        int lvl = p->getCurLevel();
        if (lvl!=0) {
            this->addBalance(price);
            p->deImprov();
        }
        else {
            cout << "No improvement!" << endl;
        }
    }
}

void Player::makeMortgage(string com) {
    istringstream iss(com); 
    string c = "";
    iss >> c;
    
    string property="";
    iss >> property;
    
    Building *prop = dynamic_cast<Building *>(gb->getTile(property));

    // check if it's an academix building with improvements
    AcadBuilding *isAB = dynamic_cast<AcadBuilding *>(prop);
    if (isAB) {
        if (isAB->getCurLevel() != 0) {
            cout << "Please sell improvements first!" << endl;
            return;
        }
    }

    int cost = prop->getCost();
    prop->setMort(cost*0.5);
    this->addBalance(cost*0.5);
}

void Player::unMortgage(string com) {
    istringstream iss(com); 
    string c = "";
    iss >> c;
    
    string property="";
    iss >> property;
    
    Building *prop = dynamic_cast<Building *>(gb->getTile(property));
    
    if (!(prop->isMort())) {
        cout << "Property " << property << " is not on mortgage!" << endl;
        return;
    }

    int mortAmount = prop->getMort();
    prop->setMort(0);
    this->addBalance(-mortAmount*1.1);
}

void Player::asset() {
    cout << "Player " << this->getName() << "'s Assets:"<< endl;      
    cout << "Balance: " << this->getBalance() << endl;
    Building *build;
    for (int i=0; i<numBuilding; ++i) {
        build = dynamic_cast<Building *>(ownBuilding[i]);
        cout << build->getName() << ": cost is " << build->getCost() << endl;
    }
}
