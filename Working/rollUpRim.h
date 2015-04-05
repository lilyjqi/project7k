#ifndef __ROLLUPRIM_H__
#define __ROLLUPRIM_H__ 

#define MAX_CUPS 4

#include <iostream>
#include <cstdlib>
#include "player.h"

class rollUpRim
{
	Owner* owner;
	static rollUpRim** instance;
public:
	rollUpRim(Owner *);
	void setOwner(Owner* );
    Owner *getOwner();
    rollUpRim *getCup();
	static rollUpRim** getInstance();
    static void cleanup();
};

#endif
