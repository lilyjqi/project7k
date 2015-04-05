#include "gym.h"
#include <string>

using namespace std;

Gym::Gym(string name, int position,int rindex, int cindex, BoardDisplay *theDisplay): 
    Building(name, position, rindex, cindex,1, theDisplay) {}

void Gym::setCost() {
    cost = 150;
}

void Gym::setPay() {
    if (neighbours[0]->getOwner()==this->getOwner()) {return 10;}
    else {return 4;}
}

int Gym::getCost() {return cost;}

int Gym::getPay() {
    cout << "Roll two dices!" << endl;
    srand(time(NULL));
    int dice1 = rand()%6 + 1;
    int dice2 = rang()%6 + 1;
    int sum = dice1 + dice2;
    cout << "You've rolled " << sum << endl;
    this->setPay();
    return pay * sum;
}

void Gym::addNeighbour(Building *b) {
    neighbours = new Building *[numNeighbours];
    neighbours[0] = b;
}


