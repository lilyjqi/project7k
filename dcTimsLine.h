#ifndef __DCTIMSLIME_H__
#define __DCTIMSLIME_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class dcTimsLine: public Tile
{	int pay;
	bool landed; // defaults to true
public:
	dcTimsLine(std::string name, int index, int row, int col);
	~dcTimsLine();
	int payFee();

};

#endif

/* methods for roll doubles or using RollUpRim to be implemented in player?*/