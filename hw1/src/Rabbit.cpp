
#include "Rabbit.hpp"


#include "Badger.hpp"
#include "Empty.hpp"
#include "Fox.hpp"


Living *Rabbit::next(int pop[NUM_LIFE_FORMS])
{
	// Dies of old age
	if(this->myAge() >= RABBIT_MAX_AGE)
	{
		return new Empty(this->point);
	}

	// Dies without food
	else if(pop[GRASS] == 0)
	{
		return new Empty(this->point);
	}

	// Foxes are more populous and
	// Foxes and Badgers outnumber rabbits
	else if((pop[BADGER] < pop[FOX]) && ((pop[BADGER] + pop[FOX]) >= pop[RABBIT]))
	{
		return new Fox(this->point, 0);	
	}

	// Badgers are more populous than rabbits 
	else if(pop[BADGER] > pop[RABBIT])
	{
		return new Badger(this->point, 0);	
	}

	// Lives on and ages up
	this->age++;	
	return this;
}
