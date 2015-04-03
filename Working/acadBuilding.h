#ifndef __ACADBUILDING
#define __ACADBUILDING 

#include <iostream>
#include <cstdlib>
#include "building.h"

class AcadBuilding: public Building
{
	std::string monoBlock;
        int curLevel;
public:
	AcadBuilding(string, int, int, int, string);
	~AcadBuilding();
        
        bool isMono();
        std::string getmonoBlock;
        int getCurLevel();
	void setCost();
	void setPay();
	void addNeighbour(Building *);
        void improv();
	void notify();
        void notifyGB();
};

#endif