
#pragma once
#include "Animal.hpp"

class Fox : public Animal 
{
	private:
		const int FOX_MAX_AGE = 6; 

	public: 
		Fox (struct Point p, int a) : Animal(p, a){}
		~Fox(){}	
		
		int who() 
		{ 
			return FOX; 
		}
	
		Living *next(int pop[NUM_LIFE_FORMS]);
};
