
#include "Plain.hpp"

#include <iterator>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

void Plain::randomInit(int width)
{
	int i, j;
	for(i = 0; i < width; i++)
	{
		for(j = 0; j < width; j++)
		{	
			// Random number to determine the Living object to create
			int random = rand() % 20;	
			struct Point p = {j, i};

			switch(random)
			{
				case 0 ... 3: 
					grid[i].push_back(new Badger(p, 0));
					break;

				case 4 ... 8:
					grid[i].push_back(new Fox(p, 0));
					break;

				case 9 ... 13:	
					grid[i].push_back(new Rabbit(p, 0));
					break;

				case 14 ... 17:
					grid[i].push_back(new Grass(p));
					break;

				default:
					grid[i].push_back(new Empty(p));
					break;
			}
		}
	}
}	



Plain::Plain(std::string inputFileName)
{		
	std::ifstream file(inputFileName);

	int width = 0;	

	for(std::string line; std::getline(file, line);)
	{
		width++;
	}
	
	this->grid.resize(width);
	
	file.clear(); 	
	file.seekg(0, std::ios::beg);

	int x = 0, y = 0;

	// Loop through the strings seperated by whitespace
	for(std::string word; file >> word;)
	{
		int age;
		struct Point p = {x, y};
			
		switch(word[0])
		{
			case 'B':
			   	age = word[1] - '0';
				grid[y].push_back(new Badger(p, age)); 
				break;
	
			case 'F':
			   	age = word[1] - '0';
				grid[y].push_back(new Fox(p, age)); 
				break;
	
			case 'R':
			   	age = word[1] - '0';
				grid[y].push_back(new Rabbit(p, age));
				break;
	
			case 'G':
				grid[y].push_back(new Grass(p));
				break;
	
			case 'E':
				grid[y].push_back(new Empty(p));
				break;
		}
		
		x = (x+1) % width;
		y = x == 0 ? y+1 : y;
	}
}

void Plain::census(Living* creature, int pop[NUM_LIFE_FORMS])
{		
	int y = creature->getPoint().y;
	int x = creature->getPoint().x;
	
	int i, j;
	for(i = y-1; i <= y+1; i++)
	{
		if(i >= 0 && i < this->getWidth())
		{
			for(j = x-1; j <= x+1; j++)
			{
				if(j >= 0 && j < this->getWidth())
				{
					int index = grid[i][j]->who();
					pop[index] += 1;
				}
			}
		}
	}
}


void Plain::updateGrid(void)
{
	std::vector< std::vector<Living*> > copy(this->grid);
	
	int i, j;
	for(i = 0; i < this->getWidth(); i++)
	{
		for(j = 0; j < this->getWidth(); j++)
		{
			int pop[NUM_LIFE_FORMS] = {0, 0, 0, 0, 0}; 
			this->census(copy[i][j], pop);

			copy[i][j] = copy[i][j]->next(pop);
		}
	}

	for(i = 0; i < this->getWidth(); i++)
	{
		for(j = 0; j < this->getWidth(); j++)
		{
			// if pointers aren't the same then there is a new Living
			if(grid[i][j] != copy[i][j]) 
			{
				delete grid[i][j]; // delete the old
				grid[i][j] = copy[i][j]; // assign the new
			}
		}
	}
}


std::string Plain::gridToString(void)
{
	std::string plainString = ""; // Empty initial string
	std::string age; 

	int i, j;
	for(i = 0; i < this->getWidth(); i++)
	{
		for(j = 0; j < this->getWidth(); j++)
		{	
			// Check the state of the Living object at grid position (j, i)
			switch(grid[i][j]->who())
			{
				case BADGER:
					age = std::to_string( ( (Animal *)grid[i][j] )->myAge() ); 
					plainString += "B" + age + " ";
					break;

				case FOX:	
					age = std::to_string( ( (Animal *)grid[i][j] )->myAge() ); 
					plainString += "F" + age + " ";
					break;
				
				case RABBIT:
					age = std::to_string( ( (Animal *)grid[i][j] )->myAge() ); 
					plainString += "R" + age + " ";
					break;
				
				case GRASS:
					plainString += "G  ";
					break;
				
				case EMPTY:
					plainString += "E  ";
					break;
			}
		}
		plainString += "\n"; // When moving down a row, adds a new line to string
	}
	return plainString; 
}


void Plain::write(std::string outputFileName)
{
	std::ofstream file(outputFileName);
	file << this->gridToString();
}
