#include "SLC.h"

using namespace std;

SLC::SLC(string name, int index, int row, int col):
	Tile(name, index, row, col), move(0), winRim(false){
		cards = {-3, -2, -1, 1, 2, 3, 0, 0}
		cardsDistritbuion = {2, 6, 10, 13, 17, 21, 22, 23}
}

SLC::~SLC(){}

void SLC::drawCard(){
	int total = 24;
	int random = Board::getBoard()->getRand(total);
	for (int i = 0, i < total, i++){
		if (random <= cardsDistritbuion[i]) { break; }
	}

	if(i <= 5) { move = cards[i]; }
	else if (i = 6) { curPlayer->gotoTims();}
	else { curPlayer->moveToIndex(OSAP); }
}

int SLC::getMove() const { return move; }