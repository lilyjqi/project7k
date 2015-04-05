#include "SLC.h"

using namespace std;

SLC::SLC(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay), move(0), winRim(false){
		cards = {-3, -2, -1, 1, 2, 3, 0, 0}
		cardsDistritbuion = {2, 6, 10, 13, 17, 21, 22, 23}
}

SLC::~SLC(){}

void SLC::drawCard(){
	int total = 24;
	int random = Board::getBoard()->getRand(total);
	for (int i = 0, i < total, i++){
		if (random <= cardsDistritbuion[i]) { return i; }
	}
	return;
}

int SLC::getMove() const { return move; }

void SLC::action(Player* p){
	visit(p);
	int i = drawCard();

	if(i <= 5) { p->moveToIndex(cards[i]); } // move by cards[i] steps
	else if (i == 6) { 
		p->setLanded(false); 
		p->gotoIndex(10);
	} //
	else { p->goToIndex(0); }

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
