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
    for (int i=0; i< numNeighbours; i++) {
        AcadBuilding* ab = dynamic_cast<AcadBuilding *>(neighbours[i]);
        if (ab != NULL && ab->getmonoBlock() != this->getmonoBlock()) {
            return false;
        }
    }
    return true;
}

void AcadBuilding::setCost() {
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
    int loop = 0;
    int cost = pay;
    while (loop <= curLevel) {
        if (loop == 1) {
            if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" ||
                name == "HH" || name == "RCH" || name == "DWE" || name == "CPH" || 
                name == "LHI" || name == "BMH" || name == "OPT" || name == "EV1" || 
                name == "EV2" || name == "EV3" || name == "PHYS" || name == "B1" || 
                name == "B2" || name == "EIT" || name == "ESC")
            { cost *= 5;}
            else if (name == "C2") { cost += 122;}
            else if (name == "MC") { cost += 140;}
            else if (name == "DC") { cost += 150;}
        }
        else if (loop == 2) {
            if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" || 
                name == "RCH" || name == "DWE" || name == "CPH" || name == "EV3" || 
                name == "PHYS" || name == "B1" || name == "B2" || name == "EIT" || 
                name == "ESC" || name == "C2" || name == "DC")
            {cost *= 3;}
            else if (name == "HH") {cost += 60;}
            else if (name == "LHI" || name == "BMH") { cost += 130;} 
            else if (name == "OPT") { cost += 140;}
            else if (name == "EV1" || name == "EV2") {cost += 160;} 
            else if (name == "MC") { cost += 325;}
        }
        else if (loop == 3) {
            if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" ||
                name == "HH" || name == "RCH" || name == "DWE")
            { cost *= 3;}
            else if (name == "CPH") { cost += 320;}
            else if (name == "LHI" || name == "BMH") {cost += 350;}
            else if (name == "OPT") { cost += 380;}
            else if (name == "EV1" || name == "EV2" || name == "EV3")
            { cost += 450;}
            else if (name == "PHYS" || name == "B1") { cost += 470;}
            else if (name == "B2") { cost += 490;}
            else if (name == "EIT" || name == "ESC") { cost += 510;}
            else if (name == "C2") { cost += 550;}
            else if (name == "MC") { cost += 600;}
            else if (name == "DC") { cost += 800;}
        }
        else if (loop == 4) {
            if (name == "AL") { cost += 70;}
            else if (name == "ML") { cost += 140;} 
            else if (name == "ECH" || name == "PAS") { cost += 130;} 
            else if (name == "HH") { cost += 150;} 
            else if (name == "RCH" || name == "DWE") { cost += 175;}
            else if (name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
            { cost += 200;}
            else if (name == "EV1" || name == "EV2" || name == "EV3" || 
                    name == "PHYS" || name == "B1" || name == "B2") 
            { cost += 175;}
             else if (name == "EIT" || name == "ESC" || name == "C2" || name == "MC") 
            { cost += 200;}
            else if (name == "DC") { cost += 300;}
        }
        else if (loop == 5) {
            if (name == "AL") { cost += 90;}
            else if (name == "ML") { cost += 130;} 
            else if (name == "ECH" || name == "PAS" || name == "HH") 
            { cost += 150;} 
            else if (name == "RCH" || name == "DWE") { cost += 125;}
            else if (name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
            { cost += 200;}
            else if (name == "EV1" || name == "EV2" || name == "EV3" || 
                name == "PHYS" || name == "B1" || name == "B2" || 
                name == "EIT" || name == "ESC")
        { cost += 175;}
        else if (name == "C2" || name == "MC") 
        { cost += 200;}
        else if (name == "DC") { cost += 300;}
        }
        loop++;
    }
    return cost;
}

int AcadBuilding::getCost() {
    string name = this->getName();
    if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" || name == "HH") 
    {return cost + curLevel * 50;}
    else if (name == "RCH" || name == "DWE" || name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
    {return cost + curLevel * 100;}
    else if (name == "EV1" || name == "EV2" || name == "EV3" || name == "PHYS" || name == "B1" || name == "B2") 
    {return cost + curLevel * 150;}
    else if (name == "EIT" || name == "ESC" || name == "C2" || name == "MC" || name == "DC") 
    {return cost + curLevel * 200;}
    return 0;
}

int AcadBuilding::getImprCost() {
    string name = this->getName();
    if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" || name == "HH") 
    {return cost + curLevel * 50;}
    else if (name == "RCH" || name == "DWE" || name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
    {return cost + curLevel * 100;}
    else if (name == "EV1" || name == "EV2" || name == "EV3" || name == "PHYS" || name == "B1" || name == "B2") 
    {return cost + curLevel * 150;}
    else if (name == "EIT" || name == "ESC" || name == "C2" || name == "MC" || name == "DC") 
    {return 200;}
    return 0;
}

void AcadBuilding::addNeighbour(Building *b) {
    if (neighbours==NULL) {
        neighbours = new Building *[numNeighbours];
        neighbours[0]= b;
    }
    else {
        for (int i=0; i< numNeighbours; i++) {
            if (neighbours[i]==NULL) {
                neighbours[i]=b;
                break;
            }
        }
    }
}

void AcadBuilding::improv() {
    curLevel++;
    this->notifyDisplay();
}

void AcadBuilding::deImprov() {
    curLevel--;
    this->notifyDisplay();
}

void AcadBuilding::notifyDisplay() {
    GameBoard * gb = GameBoard::getInstance(School::getInstance(), BoardDisplay::getInstance(), rollUpRim::getInstance());
    gb->getDisplay()->updateImpro(this);
}
