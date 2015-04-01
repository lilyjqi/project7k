#ifndef __OSAP_H__
#define __OSAP_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class OSAP: public Tile
{
	int payOSAP;
public:
	osap(std::string, int, int, int);
        void collect(Player *);
};

#endif