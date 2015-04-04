#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class gooseNesting: public Tile
{
public:
	gooseNesting(string name, int index, int row, int col);
	~gooseNesting();

<<<<<<< HEAD:gooseNesting.h
	void attacked() const;
=======
	void action(Player * p);
>>>>>>> 2fd378e31ab58a8d0bb7c7efb7f8ecdc3f4c202b:Working/gooseNesting.h
};
#endif