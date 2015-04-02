#ifndef __OSAP_H__
#define __OSAP_H__ 

#include "tile.h"

class Osap: public Tile
{
	int collect;
public:
	Osap(std::string name, int index, int row, int col);
	~Osap();

	int collectOSAP() const;
};

#endif

/* add canCollectOSAP field to player */