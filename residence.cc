#include "residence.h"
#include <string>

using namespace std;

Residence::residence(string name, int position. int rindex, int cindex):
    Building (name, position, rindex, cindex,3) {}

void Residence::setCost() {
    cost = 200;
}

void Residence::setPay() {
    int count=0;
    for (int i=0; i<numNeighbour; i++) {
        if (neighbours[i]->owner==owner) {
            count++;
        }
    }
    pay = count * 25;
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

void Residence::notify() {
    for (int i=0; i<numNeighbour; i++) {
        neighbours[i]->setPay();
    }
}
