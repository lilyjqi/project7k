#include "building.h"
#include "school.h"

using namespace std;

<<<<<<< HEAD
Building::Building(string name, int position, int rindex, int cindex, int numNeighbours):
    Tile(name, position), rindex(rindex), cindex(cindex),
    numNeighbours(numNeighbours),neighbours(NULL),cost(0),mort(0),
=======
Building::Building(string name, int position, int rindex, int cindex, int numNeighbours, BoardDisplay *theDisplay):
    Tile(name, position, rindex, cindex, theDisplay),
    neighbours(NULL),cost(0),mort(0),numNeighbours(numNeighbours),
>>>>>>> b2898725b4d53faa56a2fca99a2002beb12676ce
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

