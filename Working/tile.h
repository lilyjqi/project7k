#ifndef ___TILE_H___
#define ___TILE_H___

#include <vector>

class Player;
class BoardDisplay;

class Tile {
protected:
	std::string name;
	int pos, row, col;
	std::vector <Player*> visitors; // vector of Players currently at this Tile
    BoardDisplay *theDisplay;

public:
	Tile (std::string, int, int, int,  BoardDisplay *);
	~Tile();
	
	// action is invoked when the player lands on the tile	
	virtual void action(Player * player) = 0;

	// Used to determine which Players are on this Tile (for displaying Board)
	void visit(Player *player);
	void devisit(Player *player);
	//void devisit(Player *player); /* replace unvisit by devisit */

	// Getters
	std::string getName() const;

	int getIndex() const;
	int getRindex() const;
	int getCindex() const;

	int getNumVisitor() const;
	Player* getVisitor() const;

    BoardDisplay *getDisplay();
};

#endif
