#include "residence.h"
#include <string>

using namespace std;

Residence::Residence(string name, int position, int rindex, int cindex, BoardDisplay *theDisplay):
    Building (name, position, rindex, cindex,3, theDisplay) {}

void Residence::setCost() {
    cost = 200;
}

void Residence::setPay() {
    pay = 25;
}

int Residence::getPay() {
    int count=0;
    for (int i=0; i<numNeighbours; i++) {
        Residence* rb = dynamic_cast<Residence *>(neighbours[i]);
        if (rb!=NULL && rb->getOwner()==this->getOwner()) {
            count++;
        }
    }
    return pay * count;

}

int Residence::getCost() {
    return cost;
}

void Residence::addNeighbour(Tile *b) {
    // check if this is the first time we add neighbour for residence
    if (neighbours == NULL) {
        neighbours = new Tile *[3];
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

