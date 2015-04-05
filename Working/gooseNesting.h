#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class gooseNesting: public Tile
{
public:
	gooseNesting(std::string name, int index, int row, int col, BoardDisplay *);
	~gooseNesting();
	void attacked() const;
	void action(Player * p);
};
#endif
