#ifndef __NEEDELSHALL_H__
#define __NEEDELSHALL_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class needlesHall: public Tile
{
public:
	needlesHall();
	~needlesHall();

	int drawCards();
};
#endif