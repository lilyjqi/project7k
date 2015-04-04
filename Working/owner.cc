#include "owner.h"
#include <vector>

using namespace std;

Owner::Owner(string name): 
    name(name), balance(1500), numBuilding(0), ownBuilding(vector <Buidling* >) {
//        ownBuilding = new Building *[28];
}

string Owner::getName() {
    return name;
}

void Owner::addBuilding(Building *b) {
    ownBuilding.push_back(b);
    numBuilding++;
}

void Owner::deleteBuilding(Building *b) {
    for (int i=0; i<ownBuilding.size(); ++i) {
        if (ownBuilding[i]==b) {
            ownBuilding.erase(ownBuilding.begin()+i);
            numBuilding--;
            break;
        }
    }
}


int Owner::getBalance() {
    return balance;
}

void Owner::addBalance(int b) {
    balance += b;
}
