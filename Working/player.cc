#include "player.h"
#include "building.h"
#include "gameBoard.h"
#include "acadBuilding.h"
#include "osap.h"
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

using namespace std;

Player::Player(string name, char c, int position, int rindex, int cindex): 
    Owner(name), character(c), position(position), rindex(rindex), cindex(cindex), rollDoubleFailCount(0),
    landed(true) {gb = GameBoard::getInstance(BoardDisplay::getInstance(), rollUpRim::getInstance());}

int Player::getRow() {
    return rindex;
}

int Player::getCol() {
    return cindex;
}

int Player::getPos() {
    return position;
}

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

// void Player::updateBuilding(Tile *newAb) {
//     for (int i=0; i<numBuilding; ++i) {
//         if (ownBuilding[i]->getIndex() == newAb->getIndex()) {
//             ownBuilding[i] = newAb;
//             break;
//         }
//     }
// }

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
    int die1, die2;

    srand(time(NULL));
    die1 = rand()%6+1;
    die2 = rand()%6+1;
    cout << "Die 1 is " << die1 << endl;
    cout << "Die 2 is " << die2 << endl;
    cout << "Player " << name << " rolled " << die1+die2 << endl;

    if (die1 != die2) {  
        return die1 + die2;
    }

    cout << "Doubles! Roll again!" << endl;
    return -1;
}

void Player::makeMove(int m) {
            
        // devisit previous tile
        gb->getTile(position)->devisit(this);
        notifyDisplay(gb->getTile(position));

        int newpos = position + m;
        // collectOSAP if pass by
        if (newpos > 40) {
            newpos -= 40;
            Osap *osap = dynamic_cast<Osap *>(gb->getTile(0));
            this->addBalance(osap->collectOSAP());
        }
        else if (newpos == 40) {newpos = 0;}
        else if (newpos < 0) {
            newpos = 40 + newpos;
            Osap *osap = dynamic_cast<Osap *>(gb->getTile(0));
            this->addBalance(osap->collectOSAP());
        }
        
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
                                if (cin.eof()) {return;}
                                // make improvement
                                if (decision == "y") {
                                    if (c > this->getBalance()) {
                                        this->noMoney();
                                        if (cin.eof()) {return;}
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
                            cin.ignore();
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
                    if (build->isMort()) {
                        cout << "This builiding is on mortgage. You don't need to pay!" << endl;
                        return;
                    }
                    
                    AcadBuilding *Abuild = dynamic_cast<AcadBuilding *>(t);
                    // if t is an academic building
                    if (Abuild) {

                        // if t is in a monopoly
                        if (Abuild->isMono()) {
                            if (Abuild->getCurLevel() == 0) {payAmount = (build->getPay()) * 2;}
                            else {payAmount = build->getPay();}
                        }
                        // if t is not in a monopoly
                        else {
                            payAmount = build->getPay();
                        }
                    }// if t is an academic building

                    // if t is not an academic building
                    else {
                        payAmount = build->getPay();
                    }
          
                    cout << "You have entered " << ownerName << "'s Building." << endl;
                    cout << "Please pay " << payAmount << endl;

                    if (payAmount > this->getBalance()) {
                        this->noMoney(build->getOwner());
                        if (cin.eof()) {return;}
                        if (this->getBalance() == -1) {return;}
                        cout << "You have paid " << payAmount << " dollars to " << ownerName << endl;
                        this->addBalance(-payAmount);
                        build->getOwner()->addBalance(payAmount);
                    }
                    else {
                        cout << "You have paid " << payAmount << " dollars to " << ownerName << endl;
                        this->addBalance(-payAmount);
                        build->getOwner()->addBalance(payAmount);
                    }
                }// else current player is not the owner of t
            }//if building is owned

            // if building is not owned by anyone
            else {
                int c = build->getCost();
                string n = build->getName();
                cout << "Cost of " << n << " is " << c << endl;
                cout << "Do you want to buy it?(y/n)" << endl;
                string decision="";
                while (cin >> decision) {
                    if (cin.eof()) {return;}
                    if (decision == "y") {
                        if (c > this->getBalance()) {
                            cin.ignore();
                            this->noMoney();
                            if (cin.eof()) {return;}
                            if (this->getBalance() == -1) {return;}
                            this->addBalance(-c);
                            this->addBuilding(t);
                            t->setOwner(this);
                            build->setPay();
                            school->deleteBuilding(t);
                            break;
                        }
                        else {
                            cin.ignore();
                            this->addBalance(-c);
                            this->addBuilding(t);
                            t->setOwner(this);
                            build->setPay();
                            school->deleteBuilding(t);
                            break;
                        }
                    }
                    else if (decision == "n") {
                        cin.ignore();
                        build->auction(gb);
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
            if (cin.eof()) {return;}
            else if (this->getBalance() == -1) {return;}
            this->setLanded(true);
            notify(t);
            notifyDisplay(t);
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
    Tile *currentTile = gb->getTile(this->getPos());
    currentTile->devisit(this);

    Tile *t = gb->getTile(index);
    cout << t->getName() << endl;
    position = index;
    rindex = t->getRindex();
    cindex = t->getCindex();
    if (index == 10) {this->setLanded(false);}
    notify(t);
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
    cout << "Please enter <enough> to continue!" << endl;
    
    School *school = School::getInstance();
    string command = "";
    while (getline(cin, command)) {
        if (command == "enough") {break;}
        else if (command == "bankrupt") {

            this->addBalance(-1-(this->getBalance()));
            // buildings goes to auction
            for (int i=0; i<numBuilding; ++i) {
                Building *build = dynamic_cast<Building *>(ownBuilding[i]);
                build->auction(gb);
                //ownBuilding[i]->setOwner(school);
                this->deleteBuilding(ownBuilding[i]);
                //school->addBuilding(ownBuilding[i]);
            }
            // destroy rim cups
            for (int i=0; i<4; ++i) {
                if (gb->cups[i]->getOwner() == this) {gb->cups[i]->setOwner(school);}
            }
            
            return;
        }
        
        else if (command == "asset") {
            this->asset();
        }
        
        else {
            this->threeOptions(command);
            cout << "You now have " << this->getBalance() << endl;
        }
    }// while
    if (cin.eof()) {return;}
    cin.ignore();
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

                    cout << "Player " << owes->getName() << " , do you want to unmortgage " << build->getName() << " now? (y/n)" << endl;
                    string decision = "";
                    while (cin >> decision) {
                        if (cin.eof()) {return;}
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
                    cin.ignore();

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
    if (cin.eof()) {return;}
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
        if(cin.eof()) {return;}
        if (decision == "y") {
            istringstream issgive(give);
            int g;

            // if give money, must be receiving a building
            if (!(issgive >> g).fail()) {
                while (g > this->getBalance()) {
                    this->noMoney();
                    if (this->getBalance() == -1) {return;}
                    cout << "Do you want to cancel the trade?(y/n)" << endl;
                    string yn = "";
                    while (cin >> yn) {
                        if (cin.eof()) {return;}
                        if (yn == "y") {cout << "trade cancelled!" << endl;return;}
                        else if (yn == "n") {cout << "need more money" << endl;break;}
                        else {cout << "Please enter <y> or <n>!";}
                    }
                }
                
                Building *receiveBuilding = dynamic_cast<Building *>(gb->getTile(receive));

                AcadBuilding *abuild = dynamic_cast<AcadBuilding *> (receiveBuilding);
                if (abuild) {
                    if (abuild->getCurLevel() > 0) {
                        cout << "Can't trade academic building with improvement!" << endl;
                        return;
                    }
                    else if (abuild->imprNeighbour()) {
                        cout << "Can't trade! Property in its monopoly has improvements!" << endl;
                        return;
                    }          
                }
                receiveBuilding->setOwner(this);
                this->addBuilding(receiveBuilding);
                other->deleteBuilding(receiveBuilding);

                this->addBalance(-g);
                other->addBalance(g);

            }

            // if give a building
            else {
                istringstream issreceive(receive);
                int r;
                
                Building *giveBuilding = dynamic_cast<Building *>(gb->getTile(give));
                AcadBuilding *ab = dynamic_cast<AcadBuilding *>(giveBuilding);
                if (ab) {
                    if (ab->getCurLevel() > 0) {
                        cout << "Can't trade academic building with improvement!" << endl;
                        return;
                    }
                    else if (ab->imprNeighbour()) {
                        cout << "Can't trade! Property in its monopoly has improvements!" << endl;
                        return;
                    }          
                }

                // receive money
                if (!(issreceive >> r).fail()) {
                    while (r > other->getBalance()) {
                        other->noMoney();
                        if (other->getBalance() == -1) {return;}
                    }
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
    cin.ignore();
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
        if (p->isMono()) {
            cout << "Price is " << price << endl;
            if (this->getBalance() < price) {
                cout << "You don't have enough money!" << endl;
                this->noMoney();
            }
            else {
                this->addBalance(-price);
                p->improv();
                cout << "You have improved to Level "<< p->getCurLevel() << endl;
            }
        }
        else {
            cout << "You can not make improvement!" << endl;
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
        else if (isAB->imprNeighbour()) {
            cout << "Can'r mortgage. Property in its monopoly has improments!" << endl;
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
    if (this->getPos() == 4) {
        cerr<<"Duang you are standing on Tuition - cannot display your Asset."<< endl;
        return;
    }
    cout << "Player " << this->getName() << "'s Assets:"<< endl;      
    cout << "Balance: " << this->getBalance() << endl;
    Building *build;
    for (int i=0; i<numBuilding; ++i) {
        build = dynamic_cast<Building *>(ownBuilding[i]);
        cout << build->getName() << ": " << build->getCost();
        AcadBuilding *abuild = dynamic_cast<AcadBuilding *>(build);
        if (abuild) {
            cout << ", current level is " << abuild->getCurLevel();
        }
        if (build->isMort()) {
           cout << ", on mortgage.";
        }
        cout << endl;
    }
}
