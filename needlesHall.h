#ifndef __NEEDELSHALL_H__
#define __NEEDELSHALL_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class needlesHall: public Tile
{
	int fee;
	bool winRim;
	const int cards[7];
	const int cardsDistribution[7];
public:
	needlesHall(string name, int index, int row, int col);
	~needlesHall();

	void drawCards();
	int getFee() const;
};
#endif