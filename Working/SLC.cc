#include "SLC.h"
#include "player.h"
#include "rollUpRim.h"
#include <ctime>

using namespace std;

SLC::SLC(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay){
}

SLC::~SLC(){}

int SLC::drawCard(){
	int total = 24;
	int i=0;

	srand(time(NULL));
    int random = rand()%total+1;
	for (i = 0; i < total; i++){
		if (random <= cardsDistribution[i]) { break; }
	}
	return i;
}

void SLC::action(Player* p){
	this->visit(p);
    cout << "You are now in SLC." << endl;
	srand(time(NULL));
    int random = rand()%100+1;
	if (random == 1) {
		for (int j=0; j<4; j++){
			if ((*(rollUpRim::getInstance()+j))->getOwner() != NULL) {
				(*(rollUpRim::getInstance()+j))->setOwner(p);
				cout << "Congrats! You just won a free pass!" << endl;
				return;
			}
		}
		cout << "Duang the RollUpRims are all occupied. Time to buy a lottery ticket! " << endl;
	}
    else {
	    int i = drawCard();

	    if(i <= 5) { 
            cout << "Move " << cards[i] << " Steps." << endl;
            p->makeMove(cards[i]);
        } // move by cards[i] steps
	    else if (i == 6) { 
	    	p->setLanded(false);
		    p->goToIndex(DC_TIMS_LINE);
            cout << "You are now in DC Tims Line." << endl;
	    } //
	    else { p->goToIndex(OSAP_LINE); cout << "You are now in SOAP Line." << endl; }
    }
}

void SLC::setCost(){ return; }
void SLC::setOwner(Owner*){ return; }
void SLC::addNeighbour(Tile*){ return; }
