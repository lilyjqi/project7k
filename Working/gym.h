#ifndef __GYM_H__
#define __GYM_H__ 

#include <iostream>
#include <cstdlib>
#include "building.h"
class Owner;
class Building;
class Gym: public Building
{
public:
	Gym(std::string, int, int, int, BoardDisplay *);
	~Gym();

	void setCost();
    void setPay();
    int getCost();
    int getPay();
	void addNeighbour(Tile*);
};

#endif
