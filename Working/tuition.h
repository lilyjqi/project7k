#ifndef __TUITION_H__
#define __TUITION_H__ 

#include "tile.h"

class Tuition: public Tile
{
	int pay;
public:
	Tuition(std::string name, int index, int row, int col, BoardDisplay *);
	~Tuition();

	int getTuition() const;
	void action(Player* p);
};

#endif
