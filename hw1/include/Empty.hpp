
#pragma once
#include "Living.hpp"

class Empty : public Living 
{
	public:
	Empty (struct Point p) : Living(p) {} 
	~Empty(){}	
	
	int who(void)
	{ 
		return EMPTY; 
	}

	Living *next(int pop[NUM_LIFE_FORMS]);
};
