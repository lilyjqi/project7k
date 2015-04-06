#include "goToTims.h"
#include "player.h"
using namespace std;

goToTims::goToTims(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay){
}

goToTims::~goToTims(){}

void goToTims::action(Player* p) {
	visit(p);
	p->goToIndex(DC_TIMS_LINE);//need to specify the index for Tims Line
	p->setLanded(false);
}

void goToTims::setCost(){ return; }
void goToTims::setOwner(Owner*){ return; }
void goToTims::addNeighbour(Tile*){ return; }
