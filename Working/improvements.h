#ifndef __IMPROVEMENTS_H__
#define __IMPROVEMENTS_H__ 

#include <iostream>
#include <cstdlib>
#include "ABDecorator.h"

class Improvements: public ABDecorator
{
public:
	Improvements(AcadBuilding *ab): ABDecorator(ab) {};
        
        // from tile.h
        void visit(Player *);
        void devisit(Player *);
        std::string getName();
        int getPos();
        int getRindex();
        int getCindex();
        
        // from building.h
        void setOwner(Owner *);
        void setMort(bool);

        // frim acadBuilding.h
        int getPay();
	int getCost();
        bool isMono();
        std::string getmonoBlock();
        int getCurLevel();
        void improv();
        void notifyGB(AcadBuilding *);

};

#endif