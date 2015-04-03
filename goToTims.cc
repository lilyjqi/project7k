#include "goToTims.h"

using namespace std;

goToTims::goToTims(string name, int index, int row, int col):
	Tile(name, index, row, col){
}

goToTims::~goToTims(){}

void goToTims::action(Player* p) {
	p->moveToIndex();//need to specify the index for Tims Line
	p->setLanded(false);
}