#ifndef __ACADBUILDING
#define __ACADBUILDING 

#include "building.h"

class AcadBuilding: public Building
{
	std::string monoBlock;
        int curLevel;
public:
	AcadBuilding(string, int, int, int, string);
	~AcadBuilding();
        
        bool isMono();
        std::string getmonoBlock();
        int getCurLevel();
	void setCost();
	void setPay();
        int getCost();
        int getPay();
	void addNeighbour(Building *);
        void improv();
        void notifyGB(AcadBuilding *);
};

#endif