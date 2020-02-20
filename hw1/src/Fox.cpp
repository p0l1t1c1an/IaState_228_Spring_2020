
#include "Fox.hpp"

#include "Badger.hpp"
#include "Empty.hpp"


Living *Fox::next(int pop[NUM_LIFE_FORMS])
{	
	// Dies of old age
	if(this->myAge() >= FOX_MAX_AGE)
	{
		return new Empty(this->point);
	}
		// Badgers eat the foxes 
	else if(pop[BADGER] > pop[FOX])
	{
		return new Badger(this->point, 0);
	}
		// Badger and Foxes overeat their food source
	else if((pop[BADGER] + pop[FOX]) > pop[RABBIT])
	{
		return new Empty(this->point);	
	}

	// Lives on and ages up
	this->age++;
	return this; 
}

