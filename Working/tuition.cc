#include "tuition.h"

using namespace std;

Tuition::Tuition(string name, int index, int row, int col):
	Tile(name, index, row, col), pay(300){
}

Tuition::~Tuition(){}

int Tuition::getTuition() const {
	return pay;
}

void Tuition::action(Player* p){
	visit(p);
	p->setBalance(-getTuition());
}
