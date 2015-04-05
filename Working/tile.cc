#include "tile.h"
//#include "board.h"
#include "player.h"
//#include "display.h"
#include <iostream>
using namespace std;

Tile::Tile (string name, int pos, int row, int col, BoardDisplay *theDisplay): name(name), pos(pos), row(row), col(col), theDisplay(theDisplay){
    
}

Tile::~Tile () {
    visitors.clear();
}

void Tile::visit(Player *player){
	visitors.push_back(player);
}

void Tile::devisit(Player * player) {
	vector <Player *>::iterator it = visitors.begin();
	while (*it != player)
		it++;

	visitors.erase(it);
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

// void Tile::setCost(){ return; }
// void Tile::setOwner(Owner*){ return; }
