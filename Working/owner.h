#ifndef __OWNER_H__
#define __OWNER_H__

#include <string>
#include <vector>
#include "tile.h"

class Building;

class Owner
{
  protected:
	std::string name;
	int balance;
    int numBuilding;
	std::vector<Tile *> ownBuilding;
  public:
	Owner();
        
    std::string getName();
	void addBuilding(Tile *);
    void deleteBuilding(Tile *);
	int getBalance();
	void addBalance(int b);
};

#endif
