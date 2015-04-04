#include "building.h"
#include "school.h"

Building::Building(string name, int position, int rindex, int cindex, int numNeighbours):
    Tile(name, position, rindex, cindex),
    numNeighbours(numNeighbours),neighbours(NULL),cost(0),mort(false),o(School::getInstance()) {}

void Building::setOwner(Owner * o) {
    owner = o;
}


void Building::setMort(bool b) {
    mort = b;
}

bool Building::isMort() {
    return mort;
}


