#ifndef __BUILDING_H__
#define __BUILDING_H__ 

#include <iostream>
#include <cstdlib>
#include "boardDisplay.h"

class Building: public Tile{

  protected:
	int numNeighbours;
	Building* neighbours[4];
	int cost;
        int pay;
	bool mort;

  public:
        Building();
	virtual ~Building() = 0;
	virtual void setCost() = 0;
	virtual void setPay() = 0;
	virtual void addNeighbour(Building *) = 0;
        virtual void notify() = 0;

        void setOwner(Owner*);
	int getPay();
        int getCost();
	void setMort(bool);
	bool isMort();
	void auction() = 0;
};

#endif