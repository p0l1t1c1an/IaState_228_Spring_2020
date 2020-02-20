
#pragma once
#include "Living.hpp" 

class Grass : public Living 
{
	public:
		Grass(struct Point p) : Living(p) {} 
		~Grass(){}	

		int who(void)
		{ 
			return GRASS; 
		}

		Living *next(int pop[NUM_LIFE_FORMS]);
};
