#ifndef __TILE_H__
#define __TILE_H__

#include <iostream>
#include <string>
#include "window.h"

class Tile {
	std::string name;
	int position;
	int rindex;
	int cindex;
	Owner* owner;
        boardDisplay * display;
  public:
        std::string getName();
  	Owner* getOwner();
  	int getRow();
  	int getColumn();

  	Tile();
  	~Tile();
};

#endif