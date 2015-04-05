#include "tuition.h"
#include "player.h"
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
	p->addBalance(-getTuition());
}

void Tuition::setCost(){ return; }
void Tuition::setOwner(Owner*){ return; }
void Tuition::addNeighbour(Tile*){ return; }
