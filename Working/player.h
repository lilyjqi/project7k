#ifndef __PLAYER_H__
#define __PLAYER_H__ 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "owner.h"

class Player: public Owner
{
	char character;
	int position;
	int rindex;
	int cindex;
        GameBoard *gb;
  public:
	Player(string, char, int, int, int);

  	int getRow();
  	int getCol();
        int getWorth();
  	bool isDouble();
  	void makeMove();
  	void notify(Tile *);
};

#endif