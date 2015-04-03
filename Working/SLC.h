#ifndef __SLC_H__
#define __SLC_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class SLC: public Tile
{
	bool winRim;
	const int cards[8]; // add goToTims or movetoIndex to Player
	const int cardsDistribution[8];
public:
	SLC(string name, int index, int row, int col);
	~SLC();

	void drawCard();
	int getMove() const;
	void action(Player* p);

};
#endif