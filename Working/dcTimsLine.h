#ifndef __DCTIMSLIME_H__
#define __DCTIMSLIME_H__ 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "rollUpRim.h"
#include "Owner.h"
#include "tile.h"

class Player;
class Building;
class Owner;
class dcTimsLine: public Tile
{

public:
	dcTimsLine(std::string name, int index, int row, int col, BoardDisplay *);
	~dcTimsLine();

    void action(Player* p);

	void setCost();
    void setOwner(Owner*);
    void addNeighbour(Tile*);
};

#endif

