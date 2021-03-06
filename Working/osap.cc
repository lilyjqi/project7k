#include "osap.h"
#include "player.h"
#include <iostream>

using namespace std;

Osap::Osap(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay), collect(200){
}

Osap::~Osap(){}

int Osap::collectOSAP() const { cout << "Collect OSAP" << endl; return collect; }

void Osap::action(Player* p) {
	visit(p);
	p->addBalance(collectOSAP());
}


void Osap::setCost(){ return; }
void Osap::setOwner(Owner*){ return; }
void Osap::addNeighbour(Tile*){ return; }
