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
	Building *ownBuilding;
  public:
	Owner();

	void addBuilding(Building *);
	int getBalance();
	void setBalance(int b);
};

#endif
