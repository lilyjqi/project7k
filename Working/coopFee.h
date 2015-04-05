#ifndef __COOPFEE_H__
#define __COOPFEE_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class Player;
class Owner;
class Building;
class coopFee: public Tile
{
	int fee;
public:
	coopFee(std::string name, int index, int row, int col, BoardDisplay *);
	~coopFee();

	int getFee();
	void action(Player* p);

	void setCost();
    void setOwner(Owner*);
    void addNeighbour(Tile*);

};
#endif
