#ifndef __DCTIMSLIME_H__
#define __DCTIMSLIME_H__ 

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "rollUpRim.h"
#include "Owner.h"
#include "tile.h"

class Player;

class dcTimsLine: public Tile
{
<<<<<<< HEAD

=======
	//bool landed; // defaults to true
>>>>>>> 5436440ceeba075043959f42abfc083e408d1e81
public:
	dcTimsLine(std::string name, int index, int row, int col, BoardDisplay *);
	~dcTimsLine();

	//void setFee();
	//int payFee();
	void action(Player* p);
	//void setLanded(bool isLanded);

};

#endif

/* methods for roll doubles or using RollUpRim to be implemented in player?*/
