#ifndef __BOARDDISPLAY_H__
#define __BOARDDISPLAY_H__ 

#include "owner.h"
#include "tile.h"

class BoardDisplay
{
    static BoardDisplay *instance;
    std::string **display;
public:
	BoardDisplay();
    static BoardDisplay *getInstance();
    static void cleanup();
    void updateImpro(Tile *);
    void updatePos(Tile *);
    friend std::ostream& operator<<(std::ostream& out, const BoardDisplay& d);
};

#endif
