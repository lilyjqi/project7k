#include "player.h"
#include "gameboard.h"
#include <string>

using namespace std;

Player::Player(string name, char c, int position, int rindex, int cindex): 
    Owner(name), character(c), position(position), rindex(rindex), cindex(cindex),
    landed(true) {gb = GameBoard::getInstance();}

int Player::getRow() {
    return rindex;
}

int Player::getCol() {
    return cindex;
}

string Player::getName() {
    return name;
}

char Player::getChar() {
    return character;
}

int Player::getWorth() {
    int w=balance;
    for (int i=0; i<numBuilding; i++) {
        w += ownBuilding[i]->getCost();
    }
    return w;
}

void setLanded(bool isLanded) {landed = isLanded;}

bool Player::isDouble() {
    srand(time(NULL));
    int dice1 = rand()%6+1;
    int dice2 = rand()%6+1;
    cout << "Player " << name << " rolled " << dice1 << " and " << dice2 << endl;
    if (dice1 == dice2) {
        cout << "Get out of Tims Line!"
        return true;
    }
    return false;
}

void addBalance(int money) {
    balance += money;
}

void Player::makeMove() {

    // roll dices
    int numRoll=0;
    for (int i=0; i<3; ++i) {
        srand(time(NULL));
        int dice1 = rand()%6+1;
        int dice2 = rand()%6+1;
        cout << "Player " << name << " rolled" << dice1+dice2 << endl;

        // if didn't roll doubles
        if (dice1 != dice2) {  
            int newpos = pos+ dice1 + dice2;
            
            // devisit previous tile
            gb->getTile(pos)->devisit(this);

            // collectOSAP if pass by
            if (newpos > 40) {
                newpos -= 40;
                this->addBalance(gb->getTile(0)->collectOSAP())；
            }
            else if (newpos == 40) {newpos = 0;}

            // move to new pos and take action
            Tile * t = gb->getTile(newpos);
            position = newpos;
            rindex = t->getRow();
            cindex = t->getCol();
            this->setLanded(true);
            notify(t);
            notifyDisplay(t);
            return;
        }

        cout << "Doubles! Roll again!" << endl;
    }
    // if roll doubles three times
    cout << "Three sets of doubles in a row. Sent to DC Tims Line!" << endl;
    this->goToTims();
}

void Player::makeMove(int i) {
    int newpos = pos + i;

     // collectOSAP if pass by
    if (newpos > 40) {
        newpos -= 40;
        this->addBalance(gb->getTile(0)->collectOSAP())；
    }
    else if (newpos == 40) {newpos = 0;}

    Tile * t = gb->getTile(newpos);
    position = newpos;
    rindex = t->getRow();
    cindex = t->getCol();
    this->setLanded(true);
    notify(t);
    notifyDisplay(t);
}

void Player::notify(Tile * t) {
    t->action(this);
}

void Player::notifyDisplay(Tile *t) {
    gb->getDisplay()->updatePos(t);
}

void Player::goToTims() {
    Tile *t = gb->getTile(10);
    this->setLanded(false);
    notify(t);
    notifyDisplay(t);
    position = 10;
    rindex = t->getRow();
    cindex = t->getCol();
}
