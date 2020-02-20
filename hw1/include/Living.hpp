
#pragma once 
#define NUM_LIFE_FORMS 5 

enum State 
{
	BADGER, EMPTY, FOX, GRASS, RABBIT 
};

struct Point
{	
	int x, y;
}; 

class Living 
{
	protected: 	
		struct Point point; // location of living thing

	public:
		Living(struct Point p) : point(p) {}
		virtual ~Living(void) {}

		struct Point getPoint(void)
		{
			return point;
		}

		virtual int who() = 0;
		virtual Living* next(int pop[NUM_LIFE_FORMS]) = 0; 
};
