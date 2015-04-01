#include "gym.h"
#include <string>

using namespace std;

Gym::Gym(string name, int position,int rindex, int cindex): 
    Building(name, position, rindex, cindex,1) {}

void Gym::setCost() {
    cost = 150;
}

void Gym::setPay() {
    if (neighbours[0]->getOwner()==this->getOwner()) {return 10;}
    else {return 4;}
}

void Gym::addNeighbour(Building *b) {
    neighbours = new Building *[numNeighbours];
    neighbours[0] = b;
}

void Gym::notify() {
    for (int i=0; i<numNeighbour; i++) {
        neighbours[i]->setPay();
    }
}
