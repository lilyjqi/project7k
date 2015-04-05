#include "tuition.h"

using namespace std;

Tuition::Tuition(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay), pay(300){
}

Tuition::~Tuition(){}

int Tuition::getTuition() const {
	return pay;
}

void Tuition::action(Player* p){
	visit(p);
	p->setBalance(-getTuition());
}
