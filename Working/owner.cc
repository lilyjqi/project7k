#include "owner.h"

using namespace std;

Owner::Owner(string name): 
    name(name), balance(1500), numBuilding(0) {
        ownBuilding = new Building *[28];
    };

void Owner::addBuilding(Building *b) {
    for (int i=0; i<28; i++) {
        if (ownBuilding[i]==NULL) {
            ownBuilding[i]=b;
            numBuilding++;
        }
    }
}

void Owner::deleteBuilding(Building *b) {
    for (int i=0; i<28; i++) {
        if (ownBuilding[i]==b) {
            ownBuilding[i]=NULL;
            numBuilding—;
        }
    }
   
}


int Owner::getBalance() {
    return balance;
}

void Owner::setBalance(int b) {
    balance += b;
}
