#ifndef __IMPROVEMENTS_H__
#define __IMPROVEMENTS_H__ 

#include <iostream>
#include <cstdlib>
#include "ABDecorator.h"

class Improvements: public ABDecorator
{
        int curLevel;
public:
	Improvements(int curLevel,AcadBuilding *ab): ABDecorator(ab),curLevel(curLevel) {};
        int getCurLevel();
        std::string getName();
	int getCost();
        int getPay();
};

#endif