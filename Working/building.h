#ifndef __BUILDING_H__
#define __BUILDING_H__ 

#include <iostream>
#include "boardDisplay.h"
#include "tile.h"

class Owner;

class Building: public Tile{

  protected:
    Building** neighbours;
    int cost;
    int pay;
    int mort;
    int numNeighbours;
    Owner* owner;
  public:
    Building(std::string, int, int, int, int);
	virtual ~Building() = 0 ;
	virtual void setCost() = 0;
	virtual void setPay() = 0;
	virtual void addNeighbour(Building *) = 0;
	virtual int getPay() = 0;
    virtual int getCost() = 0;

    void setOwner(Owner*);
    void getOwner() const;
	void setMort(int);
	bool isMort();
    int getMort();
	virtual void auction() = 0;
};

#endif
