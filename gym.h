#ifndef __GYM_H__
#define __GYM_H__ 

#include <iostream>
#include <cstdlib>
#include "building.h"

class Gym: public Building
{
public:
	Gym(string, int, int, int);
	~Gym();

	void setCost();
        void setPay();
	void addNeighbour(Building *);
        void notify(); //notify neighbours of owner change
};
#endif