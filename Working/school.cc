#include "school.h"

using namespace std;

School *School::getInstance() {
    if (!instance) {
        instance = new School;
        atexit(cleanup);
    }
    return instance;
}

School::School(): Owner("School") {};

void School::cleanup() {
    delete instance;
}
