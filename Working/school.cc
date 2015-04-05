#include "school.h"
#include <cstdlib>

using namespace std;

School *School::getInstance() {
    if (!instance) {
        instance = new School;
        atexit(cleanup);
    }
    return instance;
}

School::School(): Owner("Bank") {};

void School::cleanup() {
    delete instance;
}
