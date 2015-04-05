#include "residence.h"
#include <string>

using namespace std;

Residence::Residence(string name, int position. int rindex, int cindex, BoardDisplay *theDisplay):
    Building (name, position, rindex, cindex,3, theDisplay) {}

void Residence::setCost() {
    cost = 200;
}

void Residence::setPay() {
    pay = 25;
}

int getPay() {
    int count=0;
    for (int i=0; i<numNeighbour; i++) {
        if (neighbours[i]->getOwner()==this->getOwner()) {
            count++;
        }
    }
    return pay * count;

}

int getCost() {
    return cost;
}

void Residence::addNeighbour(Building *b) {
    // check if this is the first time we add neighbour for residence
    if (neighbours == NULL) {
        neighbours = new Building *[3];
        neighbours[0] = b;
    }//if

    // if we already have a neighbour array
    else {
        for (int i=1; i<3; i++) {
            if (neighbours[i]==NULL) {
                neighbours[i]=b;
                break;
            }//if
        }//for
    }//else
}

