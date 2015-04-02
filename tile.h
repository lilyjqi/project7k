/*******************************************
 *  BB7K | CS246 Fall 2014                 *
 *  Developed by Eric Bai and Jerry Yu     *
 *  https://github.com/hweetty/bb7k        *
 *                                         *
 *  Please do not use any portion of this  *
 *  code in future academic assignments.   *
 *  You have been warned.                  *
 *******************************************/
 
#ifndef ___TILE_H___
#define ___TILE_H___

#define MAX_PLAYER 8

#include <string>
#include <vector>
#include <iostream>

//class Display;
class Player;

class Tile {
protected:
	std::string name;
//	Display * display;
	int pos, row, col;
	std::vector <Player*> visitors; // List of Players currently at this Tile
	Player* curPlayer; //the current player is the last in the vector, use pushback to retrieve

public:
	Tile (std::string name, int pos);
	virtual ~Tile() = 0;
	
	// action is invoked when the player lands on the tile	
	virtual void action(Player * player) = 0; /* replace execute by action */

	// Used to determine which Players are on this Tile (for displaying Board)
	void visit(Player *player);
	void devisit(Player *player); /* replace unvisit by devisit */

	// Getters
	std::string getName() const;
	int getIndex() const;
	int getRow() const;
	int getCol() const;

//	void setDisplay(Display * d);
//	void updateVisitorDisplay();
};

#endif