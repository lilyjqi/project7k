#ifndef __SLC_H__
#define __SLC_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class SLC: public Tile
{
public:
	SLC(arguments);
	~SLC();

	int drawCard();

};
#endif