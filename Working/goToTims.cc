#include "goToTims.h"

using namespace std;

goToTims::goToTims(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay){
}

goToTims::~goToTims(){}

void goToTims::action(Player* p) {
	visit(p);
	p->moveToIndex();//need to specify the index for Tims Line
	p->setLanded(false);
}
