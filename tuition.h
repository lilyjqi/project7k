#ifndef __TUITION_H__
#define __TUITION_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class tuition: public Tile
{
	int pay;
public:
	tuition(string name, int index, int row, int col);
	~tuition();

	int getTuition() const;
};

#endif