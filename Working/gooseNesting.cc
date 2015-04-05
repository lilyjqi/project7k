#include "gooseNesting.h"

using namespace std;

gooseNesting::gooseNesting(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay){
}

gooseNesting::~gooseNesting(){}

void gooseNesting::action (Player *p) {
	visit(p);
	cout << "Attacked by geese" << endl;
}

void gooseNesting::setCost(){ return; }
void gooseNesting::setOwner(Owner*){ return; }
void gooseNesting::addNeighbour(Tile*){ return; }
