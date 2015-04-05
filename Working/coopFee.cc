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
	p->addBalance(-getFee());
}
