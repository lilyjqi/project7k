#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__ 

#define DC_TIMS_LINE 10

#define OSAP_LINE 0

#include <iostream>
#include <cstdlib>
#include "tile.h"

class Building;
class Owner;
class goToTims: public Tile
{
public:
	goToTims(std::string name, int index, int row, int col, BoardDisplay *);
	~goToTims();

	void action(Player* p);
	void setCost();
    void setOwner(Owner*);
    void addNeighbour(Tile*);
};

#endif
