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
        bool landed;
        GameBoard *gb;
  public:
	Player(string, char, int, int, int);

  	int getRow();
  	int getCol();
        string getName();
        char getChar();
        int getWorth();
        void setLanded(bool);

  	bool isDouble();
  	void makeMove();
        void makeMove(int); 
  	void notify(Tile *);
        void notifyDisplay(Tile *);
        void goToTims();
};

#endif