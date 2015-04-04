#ifndef __SCHOOL_H__
#define __SCHOOL_H__ 

#include <string>
#include "owner.h"

class School: public Owner
{
private:
        static School *instance;
public:
	School();
        static School *getInstance();
        static void cleanup();

};

#endif