#include "rollUpRim.h"

using namespace std;

rollUpRim ** rollUpRim::instance = 0;

rollUpRim ** rollUpRim::getInstance() {
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

void rollUpRim::cleanup() {
    for (int i=0; i<4; i++) {
         delete instance[i];
    }
    delete [] instance;
}
