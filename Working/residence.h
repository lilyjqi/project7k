#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__ 

#include <iostream>
#include <cstdlib>
#include "building.h"

class Residence
{
public:
	Residence(string, int, int, int);
	~Residence();

	void setCost();
	void setPay();
	void addNeighbour();
        void notify();//notify neighbour of owner change
};

#endif