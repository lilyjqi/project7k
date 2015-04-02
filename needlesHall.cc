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
	int random = Board::getBoard()->getRand(total);
	for (int i = 0, i < total, i++){
		if (random <= cardsDistritbuion[i]) { break; }
	}

	fee = cards[i];
}

int needlesHall::getFee() const { return fee; }