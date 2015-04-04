#include "gooseNesting.h"

using namespace std;

gooseNesting::gooseNesting(string name, int index, int row, int col):
	Tile(name, index, row, col){
}

gooseNesting::~gooseNesting(){}

void gooseNesting::action (Player *p) {
	visit(p);
	cout << "Attacked by geese" << endl;
}
