#ifndef __OSAP_H__
#define __OSAP_H__ 

#include "tile.h"
class Owner;
class Building;

class Osap: public Tile
{
	int collect;
public:
	Osap(std::string name, int index, int row, int col, BoardDisplay *);
	~Osap();

	int collectOSAP() const;
	void action(Player* p);

	void setCost();
    void setOwner(Owner*);
    void addNeighbour(Tile*);
};

#endif

/* add canCollectOSAP field to player */
