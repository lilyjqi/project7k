#ifndef __BUILDING_H__
#define __BUILDING_H__ 

#include <iostream>
#include "boardDisplay.h"
#include "tile.h"

class Owner;

class Building: public Tile{

  protected:
    Tile** neighbours;
    int cost;
    int pay;
    int mort;
    int numNeighbours;
    Owner* owner;
  public:
    Building(std::string, int, int, int, int, BoardDisplay *);
	~Building();
	virtual void setCost() = 0;
	virtual void setPay() = 0;
	void addNeighbour(Tile *);
	virtual int getPay() = 0;
    virtual int getCost() = 0;
    //virtual void setOwner(Owner *) = 0;

    void action(Player* p);
    void setOwner(Owner*);
    Owner * getOwner() const;
	void setMort(int);
	bool isMort();
    int getMort();
	//virtual void auction() = 0;
};

#endif
