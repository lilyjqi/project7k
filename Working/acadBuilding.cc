#include "acadBuilding.h"
#include "gameBoard.h"
#include <string>

using namespace std;

AcadBuilding::AcadBuilding(string name, int position, int rindex, int cindex, string monoBlock):
    Building(name, position, rindex, cindex, 3), 
    monoBlock(monoBlock), curLevel(0) {}

int AcadBuilding::getCurLevel() {
    return curLevel;
}

string AcadBuilding::getmonoBlock() {
    return monoBlock;
}

bool AcadBuilding::isMono() {
    for (int i=0; i< numNeighbour; i++) {
        if (neighbours[i]->getmonoBlock() != this->getmonoBlock()) {
            return false;
        }
    }
    return true;
}


void AcadBuilding::setCost() {
    string name = this->getName();
    if (name == "AL") {cost = 40;}
    else if (name == "ML") {cost = 60;}
    else if (name == "ECH" || name == "PAS") {cost = 100;}
    else if (name == "HH") {cost = 120;}
    else if (name == "RCH" || name == "DWE") {cost = 140;}
    else if (name == "CPH") {cost = 160;}
    else if (name == "LHI" || name == "BMH") {cost = 180;}
    else if (name == "OPT") {cost = 200;}
    else if (name == "EV1" || name == "EV2") {cost = 220;}
    else if (name == "EV3") {cost = 240;}
    else if (name == "PHYS" || name == "B1") {cost = 260;}
    else if (name == "B2") {cost = 280;}
    else if (name == "EIT" || name == "ESC") {cost = 300;}
    else if (name == "C2") {cost = 320;}
    else if (name == "MC") {cost = 350;}
    else if (name == "DC") {cost = 400;}
}

void AcadBuilding::setPay() {
    string name = this->getName();
    if (name == "AL") {pay = 2;}
    else if (name == "ML") {pay = 4;}
    else if (name == "ECH" || name == "PAS") {pay = 6;}
    else if (name == "HH") {pay = 8;}
    else if (name == "RCH" || name == "DWE") {pay = 10;}
    else if (name == "CPH") {pay = 12;}
    else if (name == "LHI" || name == "BMH") {pay = 14;}
    else if (name == "OPT") {pay = 16;}
    else if (name == "EV1" || name == "EV2") {pay = 18;}
    else if (name == "EV3") {pay = 20;}
    else if (name == "PHYS" || name == "B1") {pay = 22;}
    else if (name == "B2") {pay = 24;}
    else if (name == "EIT" || name == "ESC") {pay = 26;}
    else if (name == "C2") {pay = 28;}
    else if (name == "MC") {pay = 35;}
    else if (name == "DC") {pay = 50;}
}

int AcadBuilding::getPay() {
    return pay;
}

int AcadBuilding::getCost() {
    return cost;
}

void AcadBuilding::addNeighbour(Building *b) {
    if (neighbours==NULL) {
        neighbours = new Building *[numNeighbour];
        neighbours[0]= b;
    }
    else {
        for (int i=0; i< numNeighbour; i++) {
            if (neighbours[i]==NULL) {
                neighbours[i]=b;
                break;
            }
        }
    }
}

void AcadBuilding::improv() {
    AcadBuilding *ab = new Improvement(this);
    notifyGB(ab);
}

void AcadBuilding::notifyGB(AcadBuilding *ab) {
    GameBoard * gb = GameBoard::getInstance();
    gb->setTile(ab);
}
