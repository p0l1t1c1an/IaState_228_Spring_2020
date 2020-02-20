
#pragma once
#include "Animal.hpp"

class Badger : public Animal
{
	private:
		const int BADGER_MAX_AGE = 4; 

	public: 	
		Badger (struct Point p, int a) : Animal(p, a){}
		~Badger(){}	
	
		int who()
		{ 
			return BADGER; 
		}
	
		Living *next(int pop[NUM_LIFE_FORMS]);	
};
