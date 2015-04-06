#include "needlesHall.h"
#include "player.h"
#include "rollUpRim.h"
#include <ctime>

using namespace std;

needlesHall::needlesHall(string name, int index, int row, int col, BoardDisplay *theDisplay):
	Tile(name, index, row, col, theDisplay), fee(0)
	{
		// cards[7] = {-200, -100, -50, 25, 50, 100, 200};
		// cardsDistribution[7] = {0, 2, 5, 11, 14, 16, 17};
}

needlesHall::~needlesHall(){}

void needlesHall::drawCards(){
	int total = 18;
	srand(time(NULL));
    int random = rand()%18+1;// need to change the name of the call
	int i = 0;
	for (i = 0;i < total;i++){
		if (random <= cardsDistribution_n[i]) { break; }
	}
    
	fee = cards_n[i];
    if (fee < 0) {cout << "Please pay " << -fee << endl;}
    else {cout << "Congrats! You have earned Manulife Scholarship for " << fee << endl;}
}

int needlesHall::getFee() const { return fee; }

void needlesHall::action(Player* p){
	this->visit(p);
    cout << "You are now in Needles Hall." << endl;

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

    else {
	    drawCards();
        while (p->getBalance() < getFee()) {
            p->noMoney();
            if (cin.eof()) {return;}
            if (p->getBalance() == -1) {return;}
        }	   
        p->addBalance(getFee());
    }
}

void needlesHall::setCost(){ return; }
void needlesHall::setOwner(Owner*){ return; }
void needlesHall::addNeighbour(Tile*){ return; }
