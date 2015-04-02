/*******************************************
 *  BB7K | CS246 Fall 2014                 *
 *  Developed by Eric Bai and Jerry Yu     *
 *  https://github.com/hweetty/bb7k        *
 *                                         *
 *  Please do not use any portion of this  *
 *  code in future academic assignments.   *
 *  You have been warned.                  *
 *******************************************/
 
#include "ownableTile.h"
#include "display.h"
#include "player.h"
#include "monopoly.h"
#include <iostream>
using namespace std;

OwnableTile::OwnableTile(string name, int index, int row, int col): 
	Tile(name, index, row, col), mortgaged(false), owner(NULL), monopoly(NULL) {
	
}

OwnableTile::~OwnableTile(){}

// needs a observer pattern notify??
void OwnableTile::action(Player * player) {
	if (!owner && player->purchaseTile(this, getPurchaseCost())) {
		owner = player;
		cout << "Player " << player->name << " purchases " << this->name << endl;
		// A player can buy a property, go into bankruptcy, then mortgage any property
	}
	// else if (owner && owner != player && !mortgaged) {
	// 	// Check bankruptcy
	// 	if (!player->payRentTo(owner, getCost(), this)) {
	// 		// Ensure corner case: player bankrupts, owner needs to pay player's mortgage, owner bankrupts
			
	// 	}
	// }
}

int OwnableTile::getPurchaseCost() {
	//return pricingInfo[0]; // Index 0 is purchase cost
	return purchaseCost;
}

void OwnableTile::setOwner(Player * p){
	owner = p;
	//display->updateOwnable(index, player? player->getPiece():' ', false);
}

Player * OwnableTile::getOwner() {
	return owner;
}

bool OwnableTile::inMonopoly(){
	return monopoly->isMonopoly();
}


void OwnableTile::setPricingInfo(const int p) { /* replace by setBasePrice ??? */
	basePrice = p;
}

void OwnableTile::setMonopoly(Monopoly *m){
	monopoly = m;
}

Monopoly *OwnableTile::getMonopoly(){
	return monopoly;
}


/* Mortgage */

bool OwnableTile::isMortgaged() {
	return mortgaged;
}

// bool OwnableTile::canMortgage() {
// 	return !mortgaged;
// }

void OwnableTile::mortgage(bool update) {
	if (mortgaged) {
		cerr << "OwnableTile::mortgage - cannot mortgage tile" << endl;
		return;
	}
	mortgaged = true;
	//cerr << "2" << endl;
	owner->gainLoseMoney(purchaseCost/2);
	//cerr << "3" << endl;
	//if(update) display->updateOwnable(index, owner->getPiece(), mortgaged);
	//cerr << "4" << endl;
	//*display << owner->getName() << " mortgaged " << *this << " to receive $" << getPurchaseCost()/2 << ".\n";
}

void OwnableTile::unmortgage(bool update) {
	if (!mortgaged) {
		cerr << "OwnableTile::unmortgage - property not mortgaged" << endl;
		return;
	}
	mortgaged = false;
	owner->gainLoseMoney(-purchaseCost*0.55); // 50% + 10% of 50% = 55% = 11/20
	//if(update) display->updateOwnable(index, owner->getPiece(), mortgaged);
	//*display << owner->getName() << " unmortgaged " << *this << " for $" << getPurchaseCost()*11/20 << ".\n";
}

OwnableTile *OwnableTile::oneAwayFromMonopoly(){
	return monopoly->almostMonopoly(this); /* replace oneAway.. by almost.. */
}