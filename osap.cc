#include "osap.h"

using namespace std;

OSAP::osap(string name, int position, int rindex, int cindex):
    Tile(name, position, rindex, cindex), payOSAP(200) {};

void OSAP::collect(Player *p) {
    p->setBalance(payOSAP);
}
