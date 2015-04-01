#ifndef __ROLLUPRIM_H__
#define __ROLLUPRIM_H__ 

#define MAX_CUPS 4

#include <iostream>
#include <cstdlib>
#include "player.h"

class rollUpRim
{
	Player* owner;
	static rollUpRim** instance;
public:
	void setOwner(Owner* );
	static rollUpRim* getInstance();
	rollUpRim(Owner *);
};

#endif