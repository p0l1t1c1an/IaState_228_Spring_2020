
#include "Badger.hpp"

#include "Fox.hpp"
#include "Empty.hpp"

Living *Badger::next(int pop[NUM_LIFE_FORMS])
{
	// Dies of old age
	if(this->myAge() >= BADGER_MAX_AGE) // 
	{
		return new Empty(this->point);
	}

	// Alone and killed by gang of foxes
	else if(pop[BADGER] == 1 && pop[FOX] > 1)
	{
		return new Fox(this->point, 0);
	}

	// Foxes and badgers over eat their food source
	else if((pop[BADGER] + pop[FOX]) > pop[RABBIT])
	{
		return new Empty(this->point);	
	}

	// Lives on and ages up
	this->age++;
	return this;
}
