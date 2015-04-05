#ifndef __NEEDELSHALL_H__
#define __NEEDELSHALL_H__ 

#include <iostream>
#include <cstdlib>
#include "tile.h"

class Owner;
class Building;

const int cards_n[7] = {-200, -100, -50, 25, 50, 100, 200};
const int cardsDistribution_n[7] = {0, 2, 5, 11, 14, 16, 17};

class needlesHall: public Tile
{
	int fee;
public:
	needlesHall(std::string name, int index, int row, int col, BoardDisplay *);
	~needlesHall();

	void drawCards();
	int getFee() const;
	void action(Player* p);

	void setCost();
    void setOwner(Owner*);
    void addNeighbour(Tile*);
};
#endif
