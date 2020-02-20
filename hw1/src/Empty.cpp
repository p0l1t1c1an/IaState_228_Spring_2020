
#include "Empty.hpp"

#include "Badger.hpp"
#include "Fox.hpp"
#include "Grass.hpp"
#include "Rabbit.hpp"


Living *Empty::next(int pop[NUM_LIFE_FORMS])
{
	// Rabbits get first dibbs on empty land 
	if(pop[RABBIT] > 1)
	{
		return new Rabbit(this->point, 0);
	}

	// Next the foxes get the space
	else if(pop[FOX] > 1)
	{
		return new Fox(this->point, 0);
	}

	// Then the Badger takes the empty space
	else if(pop[BADGER] > 1)
	{
		return new Badger(this->point, 0);	
	}

	// if non of the animalss are around, then grass gets the area
	else if(pop[GRASS] >= 1)
	{	
		return new Grass(this->point);	
	}

	// If its surrounded by empty space then the space is still empty
	return this; 
}

