#ifndef __PLAYER_H__
#define __PLAYER_H__ 

#include <string>
#include "owner.h"

class Player: public Owner
{
	char character;
	int position;
	int rindex;
	int cindex;
	int rollDoubleFailCount;
        bool landed;
        GameBoard *gb;
  public:
	Player(string, char, int, int, int);

  	int getRow();
  	int getCol();
        char getChar();
        int getWorth();
        void setLanded(bool);
        void updateBuilding(AcadBuilding *);

  	bool isDouble();
        int rollDices();
        void makeMove(int); 
  	void notify(Tile *);
        void notifyDisplay(Tile *);
        void goToTims();
        void getRollDoubleFailCount();
        void setRollDoubleFailCount();
};

#endif
