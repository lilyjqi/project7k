#include "tile.h"
#include "player.h"
#include <iostream>
using namespace std;

Tile::Tile (string name, int pos, int row, int col, BoardDisplay *theDisplay): name(name), pos(pos), row(row), col(col), theDisplay(theDisplay){
    
}

Tile::~Tile () {
    visitors.clear();
}

void Tile::visit(Player *player){
	visitors.push_back(player);
    player->notifyDisplay(this);
}

void Tile::devisit(Player * player) {
    for (int i=0; i<visitors.size(); ++i) {
        if (visitors[i] == player) {
	        visitors.erase(visitors.begin()+i);
            break;
        }
    }
    player->notifyDisplay(this);
    return;
}

string Tile::getName() const {
	return name;
}

int Tile::getIndex() const {
	return pos;
}

int Tile::getRindex() const{
	return row;
}

int Tile::getCindex() const {
	return col;
}


int Tile::getNumVisitor() const{
	return visitors.size();
}

vector<Player *> Tile::getVisitor() const {
	return visitors;
}

BoardDisplay *Tile::getDisplay() {
    return theDisplay;
}


