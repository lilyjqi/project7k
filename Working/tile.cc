#include "tile.h"
#include "board.h"
#include "player.h"
#include "display.h"
#include <iostream>
using namespace std;

Tile::Tile (string name, int pos, int row, int col): name(name), pos(pos), row(row), col(col), visitors(vector <Player*> ()){
}

Tile::~Tile () {

}

void Tile::visit(Player *player){
	visitors.push_back(player);
	//updateVisitorDisplay();
}

void Tile::devisit(Player * player) {
	list <Player *>::iterator it = visitors.begin();
	while (*it != player)
		it++;

	visitors.erase(it);
	//updateVisitorDisplay();
}

string Tile::getName() const {
	return name;
}

int Tile::getIndex() const { /* replace by getPos ??? */
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

Player* Tile::getVisitor() const {
	return visitors;
}
// void Tile::setDisplay(Display * d){
// 	display = d;
// }

// void Tile::updateVisitorDisplay(){
// 	if(pos == DC_LINE_TILE_INDEX){
// 		list<char> inLine;
// 		list<char> notInLine;
// 		for (list<Player *>::iterator it=visitors.begin() ; it != visitors.end(); ++it){
// 			if((*it)->getTurnsInLine() == -1){
// 				notInLine.push_back((*it)->getPiece());
// 			}
// 			else{
// 				inLine.push_back((*it)->getPiece());
// 			}
// 		}
// 		display->updateVisitors(pos, notInLine, inLine);
// 	}
// 	else{
// 		list<char> v;
// 		for (list<Player *>::iterator it=visitors.begin() ; it != visitors.end(); ++it){
// 			v.push_back((*it)->getPiece());
// 		}
// 		display->updateVisitors(pos, v);
// 	}
// }
