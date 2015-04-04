#include "needlesHall.h"

using namespace std;

needlesHall::needlesHall(string name, int index, int row, int col):
	Tile(name, index, row, col), fee(0), winRim(false){
		cards = {-200, -100, -50, 25, 50, 100, 200}
		cardsDistritbuion = {0, 2, 5, 11, 14, 16, 17}
}

needlesHall::~needlesHall(){}

void needlesHall::drawCard(){
	int total = 18;
	int random = Board::getBoard()->getRand(total); // need to change the name of the call
	for (int i = 0, i < total, i++){
		if (random <= cardsDistritbuion[i]) { break; }
	}

	fee = cards[i];
}

int needlesHall::getFee() const { return fee; }

void needlesHall::action(Player* p){
	visit(p);
	drawCard();
	p->setBalance(getFee());

	int random = Board::getBoard()->getRand(100); 
	if (random == 1) {
		for (int j=0; j<4; j++){
			if ((rollUpRim::getInstance()+j)->owner != NULL) {
				(rollUpRim::getInstance()+j)->setOwner(p);
				cout << "Congrats! You just won a free pass!" << endl;
				return;
			}
		}
		cout << "Dang the RollUpRims are all occupied. Time to buy a lottery ticket! " << endl;
	}
}
