/*******************************************
 *  BB7K | CS246 Fall 2014                 *
 *  Developed by Eric Bai and Jerry Yu     *
 *  https://github.com/hweetty/bb7k        *
 *                                         *
 *  Please do not use any portion of this  *
 *  code in future academic assignments.   *
 *  You have been warned.                  *
 *******************************************/
 
#ifndef ___OWNABLETILE_H___
#define ___OWNABLETILE_H___
#include "tile.h"
class Player;
class Monopoly;

class OwnableTile : public Tile {

protected:
	int purchaseCost, basePrice;
	bool mortgaged;
	//const int *pricingInfo;
	Player * owner;
	Monopoly * monopoly;

public:

	OwnableTile(std::string name, int index, int row, int col);
	virtual ~OwnableTile() = 0;

	void setOwner(Player * player);
	Player * getOwner();
	
	virtual void action(Player * player);
	virtual int getCost() = 0;
	virtual int getPurchaseCost();
	bool inMonopoly();

	void setPricingInfo(const int info[8]);
	void setMonopoly(Monopoly *m);
	Monopoly * getMonopoly();
	OwnableTile *oneAwayFromMonopoly();

/* Mortgage */	
	bool isMortgaged();
	//virtual bool canMortgage();
	void mortgage(bool update = true);
	void unmortgage(bool update = true);
};

#endif