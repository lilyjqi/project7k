#include "dcTimsLine.h"

using namespace std;

dcTimsLine::dcTimsLine(std::string name, int index, int row, int col):
	Tile(name, index, row, col), pay(50), landed(true){
}

dcTimsLine::~dcTimsLine(){
}

int dcTimsLine::payFee(){
	if(!landed) return pay;
}