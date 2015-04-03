#include "improvements.h”

using namespace std;

int Improvements::getCurLevel() {
    return 1 + ab->curLevel;
}

string Improvements::getName() {
    return ab->getName();
}

int Improvements::getPos() {
    return ab->getPos();
}

int Improvements::getRindex() {
    return ab->getRindex();
}

int Improvements::getCindex() {
    return ab->getCindex();
}

int Improvements::getCost() {
    string name = ab->getName();
    if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" || name == "HH") 
    {return ab->getCost() + 50;}
    else if (name == "RCH" || name == "DWE" || name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
    {return ab->getCost() + 100;}
    else if (name == "EV1" || name == "EV2" || name == "EV3" || name == "PHYS" || name == "B1" || name == "B2") 
    {return ab->getCost() + 150;}
    else if (name == "EIT" || name == "ESC" || name == "C2" || name == "MC" || name == "DC") 
    {return ab->getCost() + 200;}
}

int Improvements::getPay() {
    string name = this->getName();
    if (this->getCurLevel() == 1) {
        if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" ||
            name == "HH" || name == "RCH" || name == "DWE" || name == "CPH" || 
            name == "LHI" || name == "BMH" || name == "OPT" || name == "EV1" || 
            name == "EV2" || name == "EV3" || name == "PHYS" || name == "B1" || 
            name == "B2" || name == "EIT" || name == "ESC")
        { return ab->getPay() * 5;}
        else if (name == "C2") {return ab->getPay() + 122;}
        else if (name == "MC") {return ab->getPay() + 140;}
        else if (name == "DC") {return ab->getPay() + 150;}
    }
    else if (this->getCurLevel() == 2) {
        if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" || 
            name == "RCH" || name == "DWE" || name == "CPH" || name == "EV3" || 
            name == "PHYS" || name == "B1" || name == "B2" || name == "EIT" || 
            name == "ESC" || name == "C2" || name == "DC")
        {return ab->getPay() * 3;}
        else if (name == "HH") {return ab->getPay() + 60;}
        else if (name == "LHI" || name == "BMH") {return ab->getPay() + 130;} 
        else if (name == "OPT") {return ab->getPay() + 140;}
        else if (name == "EV1" || name == "EV2") {return ab->getPay() + 160;} 
        else if (name == "MC") {return ab->getCost() + 325;}
    }
    else if (this->getCurLevel() == 3) {
        if (name == "AL" || name == "ML" ||name == "ECH" || name == "PAS" ||
            name == "HH" || name == "RCH" || name == "DWE")
        {return ab->getPay() * 3;}
        else if (name == "CPH") {return ab->getPay() + 320;}
        else if (name == "LHI" || name == "BMH") {return ab->getPay() + 350;}
        else if (name == "OPT") {return ab->getPay() + 380;}
        else if (name == "EV1" || name == "EV2" || name == "EV3")
        {return ab->getPay() + 450;}
        else if (name == "PHYS" || name == "B1") {return ab->getPay() + 470;}
        else if (name == "B2") {return ab->getPay() + 490;}
        else if (name == "EIT" || name == "ESC") {return ab->getPay() + 510;}
        else if (name == "C2") {return ab->getPay() + 550;}
        else if (name == "MC") {return ab->getPay() + 600;}
        else if (name == "DC") {return ab->getPay() + 800;}
    }
    else if (this->getCurLevel() == 4) {
        if (name == "AL") {return ab->getPay() + 70;}
        else if (name == "ML") {return ab->getPay() + 140;} 
        else if (name == "ECH" || name == "PAS") {return ab->getPay() + 130;} 
        else if (name == "HH") {return ab->getPay() + 150;} 
        else if (name == "RCH" || name == "DWE") {return ab->getPay() + 175;}
        else if (name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
        {return ab->getPay() + 200;}
        else if (name == "EV1" || name == "EV2" || name == "EV3" || 
                name == "PHYS" || name == "B1" || name == "B2") 
        {return ab->getPay() + 175;}
        else if (name == "EIT" || name == "ESC" || name == "C2" || name == "MC") 
        {return ab->getPay() + 200;}
        else if (name == "DC") {return ab->getPay() + 300;}
    }
    else if (this->getCurLevel() == 5) {
        if (name == "AL") {return ab->getPay() + 90;}
        else if (name == "ML") {return ab->getPay() + 130;} 
        else if (name == "ECH" || name == "PAS" || name == "HH") 
        {return ab->getPay() + 150;} 
        else if (name == "RCH" || name == "DWE") {return ab->getPay() + 125;}
        else if (name == "CPH" || name == "LHI" || name == "BMH" || name == "OPT") 
        {return ab->getPay() + 200;}
        else if (name == "EV1" || name == "EV2" || name == "EV3" || 
                name == "PHYS" || name == "B1" || name == "B2" || 
                name == "EIT" || name == "ESC")
        {return ab->getPay() + 175;}
        else if (name == "C2" || name == "MC") 
        {return ab->getPay() + 200;}
        else if (name == "DC") {return ab->getPay() + 300;}
    }

}
