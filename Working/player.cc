#include "player.h"
#include "gameboard.h"
#include <string>

using namespace std;

Player::Player(string name, char c, int position, int rindex, int cindex): 
    Owner(name), character(c), position(position), rindex(rindex), cindex(cindex) {};

int Player::getRow() {
    return rindex;
}

int Player::getCol() {
    return cindex;
}

string Player::getName() {
    return name;
}

char getChar() {
    return character;
}

int Player::getWorth() {
    int w=balance;
    for (int i=0; i<numBuilding; i++) {
        w += ownBuilding[i]->getCost();
    }
    return w;
}

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

void Player::makeMove() {
    srand(time(NULL));
    int dice1 = rand()%6+1;
    int dice2 = rand()%6+1;

    cout << "Player " << name << " rolled" << dice1+dice2 << endl;

    int newpos = pos+ dice1 + dice2;
    if (newpos >= 40) {newpos -= 40;}
    GameBoard *gb = GameBoard::getInstance();
    Tile * t = gb->getTile(newpos);
    notify(t);

    position = newpos;
    rindex = t->getRow();
    cindex = t->getCol();
}

void Player::makeMove(int i) {
    int newpos = pos + i;
    if (newpos >=40 ) {newpos -= 40;}
    GameBoard *gb = GameBoard::getInstance();
    Tile * t = gb->getTile(newpos);
    notify(t);

    position = newpos;
    rindex = t->getRow();
    cindex = t->getCol();
}

void Player::notify(Tile * t) {
    t->action(this);
}
