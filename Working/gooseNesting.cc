#include "gooseNesting.h"

using namespace std;

gooseNesting::gooseNesting(string name, int index, int row, int col):
	Tile(name, index, row, col){
}

gooseNesting::~gooseNesting(){}

void gooseNesting::attacked () const {
	cout << "Attacked by geese" << endl;
}