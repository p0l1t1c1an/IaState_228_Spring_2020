
#pragma once
#include "Animal.hpp"

class Rabbit : public Animal 
{
	private:
		const int RABBIT_MAX_AGE = 3; 

	public:
		Rabbit(struct Point p, int a) : Animal(p, a) {}
		~Rabbit(){}	
			
		int who()
		{ 
			return RABBIT; 
		}
	
		Living *next(int pop[NUM_LIFE_FORMS]);
};
