#ifndef __BUILDING_H__
#define __BUILDING_H__ 

#include <iostream>
#include "boardDisplay.h"

class Owner;

class Building: public Tile{

  protected:
	Building** neighbours;
	int cost;
        int pay;
	bool mort;
        int numNeighbours;
        Owner* o;
  public:
        Building();
	virtual ~Building() = 0 ;
	virtual void setCost() = 0;
	virtual void setPay() = 0;
	virtual void addNeighbour(Building *) = 0;
	virtual int getPay() = 0;
        virtual int getCost() = 0;

        void setOwner(Owner*);
        void getOwner() const;
	void setMort(bool);
	bool isMort();
	void auction() = 0;
};

#endif
