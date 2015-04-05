#ifndef __ACADBUILDING_H__
#define __ACADBUILDING_H__

#include "building.h"
#include "boardDisplay.h"

class AcadBuilding: public Building
{
	std::string monoBlock;
        int curLevel;
public:
	AcadBuilding(std::string, int, int, int, std::string, BoardDisplay *);
	~AcadBuilding();
        
    bool isMono();
    std::string getmonoBlock();
    int getCurLevel();
	void setCost();
	void setPay();
    int getCost();
    int getImprCost();
    int getPay();
	void addNeighbour(Tile *);
    void improv();
    void deImprov();
    void notifyDisplay();
};

#endif
