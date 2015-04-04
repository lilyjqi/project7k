#include "rollUpRim.h"

using namespace std;

static rollUpRim ** rollUpRim::instance = 0;

static rollUpRim ** rollUpRim::getInstance() {
    if (!instance) {
        instance = new rollUpRim *[4];
        for (int i=0; i<4; i++) {
            instance[i] = new rollUpRim;
        }
        atexit(cleanup);
    }
    return instance;
}

rollUpRim::rollUpRim(Owner *o) owner(o) {}

void rollUpRim::setOwner(Owner *o) {
    owner = o;
}

Owner *rollUpRim::getOwner() {
    return owner;
}

rollUpRim * rollUpRim::getCup() {
    for (int i=0; i<4; ++i) {
        if (instance[i]->owner->getName() != "School") {
            return instance[i];
        }
    }
    return NULL;
}

static void rollUpRim::cleanup() {
    for (int i=0; i<4; i++) {
         delete instance[i];
    }
    delete [] instance;
}
