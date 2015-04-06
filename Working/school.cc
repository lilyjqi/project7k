#include "school.h"
#include <cstdlib>

using namespace std;

School* School::instance = 0;

School *School::getInstance() {
    if (!instance) {
        instance = new School;
        atexit(cleanup);
    }
    return instance;
}

School::School(): Owner("BANK") {};

void School::cleanup() {
    delete instance;
}
