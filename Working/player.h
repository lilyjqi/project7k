#ifndef __PLAYER_H__
#define __PLAYER_H__ 

#include <string>
#include "owner.h"

//#include "gameBoard.h"

class GameBoard;
class Tile;
class AcadBuilding;

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
	Player(std::string, char, int, int, int);

  	int getRow();
  	int getCol();
    char getChar();
    int getWorth();
    void setLanded(bool);
    void updateBuilding(AcadBuilding *);

  	bool isDouble();
    int rollDice();
    void makeMove(int); 
  	void notify(Tile *);
    void notifyDisplay(Tile *);
    void goToIndex(int);
    void getRollDoubleFailCount();
    void setRollDoubleFailCount();
    void threeOptions(std::string);
    void noMoney();
    void noMoney(Player *);
    void makeTrade(std::string);
    void makeImprove(std::string);
    void makeMortgage(std::string);
    void unMortgage(std::string);
    void asset();
};

#endif
