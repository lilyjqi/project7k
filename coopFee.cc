#include "coopFee.h"

using namespace std;

coopFee::coopFee(string name, int index, int row, int col):
	Tile(name, index, row, col), fee(150){}

coopFee::~coopFee(){}

int coopFee::getFee(){
	return fee;
}

void coopFee::action(Player* p){
	visit(p);
	p->setBalance(-getFee());
	devisit();
}