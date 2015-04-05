#include "building.h"
#include "school.h"

using namespace std;

void Building::action(Player* p){ return ; }

Building::Building(string name, int position, int rindex, int cindex, int numNeighbours, BoardDisplay *theDisplay):
    Tile(name, position, rindex, cindex, theDisplay),
    neighbours(NULL),cost(0),mort(0),numNeighbours(numNeighbours),
    owner(School::getInstance()) {}

Building::~Building() {
    delete [] neighbours;
}

void Building::setOwner(Owner * o) {
    owner = o;
}

void Building::setMort(int b) {
    mort = b;
}

bool Building::isMort() {
    if (mort == 0) { return false;}
    else {return true;}
}

int Building::getMort() {
    return mort;
}

Owner * Building::getOwner() const{ return owner; }

