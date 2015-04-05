#include "SLC.h"

using namespace std;

SLC::SLC(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay){
}

SLC::~SLC(){}

void: SLC::drawCard(){
	int total = 24;
	int random = Board::getBoard()->getRand(total);
	for (int i = 0; i < total; i++){
		if (random <= cardsDistritbution[i]) { return i; }
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
		p->gotoIndex(DC_TIMS_LINE);
	} //
	else { p->goToIndex(OSAP_LINE); }

	int random = Board::getBoard()->getRand(100); 
	if (random == 1) {
		for (int j=0; j<4; j++){
			if ((*(rollUpRim::getInstance()+j))->getOwner() != NULL) {
				(*(rollUpRim::getInstance()+j))->setOwner(p);
				cout << "Congrats! You just won a free pass!" << endl;
				return;
			}
		}
		cout << "Dang the RollUpRims are all occupied. Time to buy a lottery ticket! " << endl;
	}
}

void SLC::setCost(){ return; }
void SLC::setOwner(Owner*){ return; }
void SLC::addNeighbour(Tile*){ return; }
