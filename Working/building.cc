#include "building.h"
#include "school.h"

using namespace std;

Building::Building(string name, int position, int rindex, int cindex, int numNeighbours):
    Tile(name, position, rindex, cindex),
    numNeighbours(numNeighbours),neighbours(NULL),cost(0),mort(0),
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

void Building::getOwner() const{ return o; }

