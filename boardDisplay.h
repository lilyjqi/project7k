#ifndef __BOARDDISPLAY_H__
#define __BOARDDISPLAY_H__ 

#include <iostream>
#include <cstdlib>
#include "owner.h"
#include "tile.h"

class BoardDisplay
{
	int rows;
	int cols;
	char ** theDisplay;
public:
	boardDisplay();
	~boardDisplay();

	void playPos(Owner* o, int n);
	void makeImpro(Tile* t);
	std::ostream& operator<<(std::ostream& out, const boardDisplay& d);
};


#endif