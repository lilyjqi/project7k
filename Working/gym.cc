#include "gym.h"
#include <string>

using namespace std;

Gym::Gym(string name, int position,int rindex, int cindex, BoardDisplay *theDisplay): 
    Building(name, position, rindex, cindex,1, theDisplay) {}

Gym::~Gym(){}

void Gym::setCost() {
    cost = 150;
}

void Gym::setPay() {
    Gym* gym = dynamic_cast<Gym *>(neighbours[0]);
    if (gym->getOwner()==this->getOwner()) {pay = 10;}
    else {pay = 4;}
}

int Gym::getCost() {return cost;}

int Gym::getPay() {
    cout << "Roll two dices!" << endl;
    srand(time(NULL));
    int dice1 = rand()%6 + 1;
    int dice2 = rand()%6 + 1;
    int sum = dice1 + dice2;
    cout << "You've rolled " << sum << endl;
    this->setPay();
    return pay * sum;
}

void Gym::addNeighbour(Tile *b) {
    neighbours = new Tile *[numNeighbours];
    neighbours[0] = b;
}

void Gym::setOwner(Owner * o) {return;}
