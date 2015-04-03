#ifndef __OWNER_H__
#define __OWNER_H__

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "building.h"
#include "boardDisplay"
//#include "window.h"

class Owner
{
  protected:
	std::string name;
	int balance;
        int numBuilding;
	std::vector<Building *> ownBuilding;
  public:
	Owner();

	void addBuilding(Building *);
        void deleteBuilding(Building *);
	int getBalance();
	void addBalance(int b);
};

#endif
