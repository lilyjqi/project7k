#ifndef __OWNER_H__
#define __OWNER_H__

#include <string>
#include <vector>
#include "building.h"

class Building;

class Owner
{
  protected:
	std::string name;
	int balance;
    int numBuilding;
	std::vector<Building *> ownBuilding;
  public:
	Owner();
        
    std::string getName();
	void addBuilding(Building *);
    void deleteBuilding(Building *);
	int getBalance();
	void addBalance(int b);
};

#endif
