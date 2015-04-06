#include "coopFee.h"
#include "player.h"

using namespace std;

coopFee::coopFee(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay), fee(150){}

coopFee::~coopFee(){}

int coopFee::getFee(){
	return fee;
}

void coopFee::action(Player* p){
	visit(p);
    while (p->getBalance() < 150) {
        p->noMoney();
        if (cin.eof()) {return;}
        if (p->getBalance() == -1) {return;}
    }
    cout << "Paid Coop Fee of $150." << endl;
	p->addBalance(-getFee());
}

void coopFee::setCost(){ return; }
void coopFee::setOwner(Owner*){ return; }
void coopFee::addNeighbour(Tile*){ return; }
