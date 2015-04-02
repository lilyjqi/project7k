#include "osap.h"

using namespace std;

Osap::Osap(std::string name, int index, int row, int col):
	Tile(name, index, row, col), collect(200){
}

Osap::~Osap(){}

int Osap::collectOSAP(){ return collect; }