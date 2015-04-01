#include "building.h"

Building::Building(string name, int position, int rindex, int cindex, int numNeighbours):
    Tile(name, position, rindex, cindex),
    numNeighbours(numNeighbours),neighbours(NULL),cost(0),mort(false) {}

void Building::setOwner(Owner * o) {
    owner = o;
}

int Building::getpay() {
    return pay;
}

int Building::getCost() {
    return cost;
}

void Building::setMort(bool b) {
    mort = b;
}

bool Building::isMort() {
    return mort;
}


