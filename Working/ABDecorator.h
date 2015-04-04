#ifndef __ABDECORATOR_H__
#define __ABDECORATOR_H__ 

#include <iostream>
#include <cstdlib>
#include "acadBuilding.h"

class ABDecorator: public AcadBuilding
{
protected:
	AcadBuilding* ab;
	ABDecorator(AcadBuilding *ab): ab(ab) {}
	~ABDecorator() {};

};

#endif
