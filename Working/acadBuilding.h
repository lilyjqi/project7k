#ifndef __ACADBUILDING
#define __ACADBUILDING 

#include "building.h"

class AcadBuilding: public Building
{
	std::string monoBlock;
        int curLevel;
public:
	AcadBuilding(std::string, int, int, int, std::string);
	~AcadBuilding();
        
    bool isMono();
    std::string getmonoBlock();
    int getCurLevel();
	void setCost();
	void setPay();
    int getCost();
    int getImprCost();
    int getPay();
	void addNeighbour(Building *);
    void improv();
    void deImprov();
    void notifyDisplay();
};

#endif
