
#pragma once 
#include <string>
#include <vector>

#include "Badger.hpp"
#include "Empty.hpp"
#include "Fox.hpp"
#include "Grass.hpp"
#include "Rabbit.hpp"

class Plain 
{
	public:

		Plain(std::string inputFileName);
	
		Plain(int w) // assume w is greater than 0 
		{
			if(w > 0) // checks anyway
			{
				grid.resize(w);
				randomInit(w);
			}
		}

		~Plain()
		{
			int i, j;
			for(auto i : grid)
			{
				for(Living* j : i)
				{
					delete j;
				}
				i.clear();
			}
			grid.clear();
		}
		
		int getWidth()
		{ 
			return grid.size();
		}

		void updateGrid(void);
	
		std::string gridToString(void);

		void write(std::string outputFileName);

	private:		
		// mutable grid of Living objects 
		std::vector< std::vector<Living*> > grid; 
	
		void randomInit(int width);

		void census(Living* creature, int pop[NUM_LIFE_FORMS]);
};
