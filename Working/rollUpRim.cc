#include "rollUpRim.h"
#include "school.h"

using namespace std;

rollUpRim::rollUpRim(Owner *o): owner(o) {}

rollUpRim ** rollUpRim::instance = 0;

rollUpRim ** rollUpRim::getInstance() {
    School *school = School::getInstance();
    if (!instance) {
        instance = new rollUpRim *[4];
        for (int i=0; i<4; i++) {
            instance[i] = new rollUpRim(school);
        }
        atexit(cleanup);
    }
    return instance;
}

void rollUpRim::setOwner(Owner *o) {
    owner = o;
}

Owner *rollUpRim::getOwner() {
    return owner;
}

rollUpRim * rollUpRim::getCup() {
    School *school = School::getInstance();
    for (int i=0; i<4; ++i) {
        if (instance[i]->owner == school) {
            return instance[i];
        }
    }
    return NULL;
}

void rollUpRim::cleanup() {
    for (int i=0; i<4; i++) {
         delete instance[i];
    }
    delete [] instance;
}
