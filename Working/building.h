#ifndef __BUILDING_H__
#define __BUILDING_H__ 

#include <iostream>
#include "boardDisplay.h"
#include "gameBoard.h"
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
	virtual ~Building();
	virtual void setCost() = 0;
	virtual void setPay() = 0;
	virtual int getPay() = 0;
    virtual int getCost() = 0;
    virtual void addNeighbour(Tile *) = 0;
 
    void setOwner(Owner*);
    Owner * getOwner() const;
	void setMort(int);
	bool isMort();
    int getMort();
    void action(Player *);
	void auction(GameBoard *);
};

#endif
