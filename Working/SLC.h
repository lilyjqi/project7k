#ifndef __SLC_H__
#define __SLC_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

#define DC_TIMS_LINE 10
#define OSAP_LINE 0

class Owner;
class Building;

const int cards[8]= {-3, -2, -1, 1, 2, 3, 0, 0};
const int cardsDistribution[8]= {2, 6, 10, 13, 17, 21, 22, 23};

class SLC: public Tile
{
public:
	SLC(std::string name, int index, int row, int col, BoardDisplay * theDisplay);
	~SLC();

	int drawCard();
	void action(Player* p);

	void setCost();
    void setOwner(Owner*);
    void addNeighbour(Tile*);

};
#endif
