
#include "Grass.hpp"

#include "Empty.hpp"
#include "Rabbit.hpp"

Living *Grass::next(int pop[NUM_LIFE_FORMS])
{
	// Rabbits are 3 times as populous as grass and overeat
	if(pop[RABBIT] >= (pop[GRASS] * 3))
	{
		return new Empty(this->point);
	}

	// Enough rabbits take over the grass without overeating 
	else if(pop[RABBIT] >= 3)
	{
		return new Rabbit(this->point, 0);
	}

	// The grass lives on
	return this;	
}


