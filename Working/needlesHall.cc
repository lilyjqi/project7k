#include "needlesHall.h"
#include "player.h"
#include "rollUpRim.h"

using namespace std;

needlesHall::needlesHall(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay), fee(0){}

needlesHall::~needlesHall(){}

void needlesHall::drawCards(){
	int total = 18;
	srand(time(NULL));
    int random = rand()%total+1;
	int i = 0;
	for (i = 0;i < total;i++){
		if (random <= cardsDistribution_n[i]) { break; }
	}

	fee = cards_n[i];
}

int needlesHall::getFee() const { return fee; }

void needlesHall::action(Player* p){
	visit(p);
	drawCards();
	p->addBalance(getFee());

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
		cout << "Dang the RollUpRims are all occupied. Time to buy a lottery ticket! " << endl;
	}
}

void needlesHall::setCost(){ return; }
void needlesHall::setOwner(Owner*){ return; }
void needlesHall::addNeighbour(Tile*){ return; }
