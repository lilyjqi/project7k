#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__ 

#include <iostream>
#include <cstdlib>
#include "building.h"

class Residence
{
public:
	Residence(string, int, int, int, BoardDisplay *);
	~Residence();

	void setCost();
	void setPay();
        int getCost();
        int getPay();
	void addNeighbour();
};

#endif
