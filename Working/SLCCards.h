#ifndef __SLCCARDS_H__
#define __SLCCARDS_H__ 

#include <iostream>
#include <cstdlib>
#include "SLC.h"

class SLCCards
{
public:
	SLCCards(arguments);
	~SLCCards();

	int getMoves();
	void msg();
};
#endif