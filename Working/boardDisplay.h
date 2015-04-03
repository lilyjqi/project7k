#ifndef __BOARDDISPLAY_H__
#define __BOARDDISPLAY_H__ 

#include <iostream>
#include <cstdlib>
#include "owner.h"
#include "tile.h"

class BoardDisplay
{
        static BoardDisplay *instance = 0;
        string **display;
public:
	BoardDisplay();
        static BoardDisplay *getInstance();
        static void cleanup();
        void updateImpro(Tile *);
        void updatePos(Tile *);
	std::ostream& operator<<(std::ostream& out, const boardDisplay& d);
};


#endif