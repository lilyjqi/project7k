#ifndef __COOPFEE_H__
#define __COOPFEE_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class coopFee: public Tile
{
	int fee;
public:
	coopFee(string name, int index, int row, int col);
	~coopFee();

	int getFee() const;

};
#endif