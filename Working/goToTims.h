#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class goToTims: public Tile
{
public:
	goToTims(std::string name, int index, int row, int col, BoardDisplay *);
	~goToTims();

	void action(Player* p);
};

#endif
