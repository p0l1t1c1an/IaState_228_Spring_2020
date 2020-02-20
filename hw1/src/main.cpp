
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Plain.hpp"

int main(void)
{	
	int trial = 0, input = 0; // the number of trials and user input to determine grid type

	std::cout << "Simulation of Wildlife of the Plain" << std::endl <<
				 "Keys: 1 (random plain) 2 (file input) 3 (exit)" << std::endl;

	while(input != 3)
	{
		int cycles, width; // the number of cycles and width of the grid
		std::string fileName;   // the name of the file containing a grid

		std::cout << "Trial " << trial << ": ";
		std::cin >> input;

		Plain* plain;

		switch(input)
		{
			case 1:
				std::cout << "Random Plain" << std::endl <<
							 "Enter grid width: ";
				std::cin >> width;
			
				srand(time(0));	
				plain = new Plain(width);
				break;

			case 2:
				std::cout << "Plain generated from file" << std::endl <<
							 "Enter file name: ";
				std::cin >> fileName;
				
				plain = new Plain(fileName);
				break;

			case 3:
				continue; // Continue returns back to the while loop

			default:
				std::cout << "Invalid input" << std::endl << std::endl;
				continue;
		}

		std::cout << "Enter number of cycles: ";
		std::cin >> cycles;
		
		std::cout << "Initial Plain:" << std::endl <<
					 plain->gridToString() << std::endl;

		int i;
		for(i = 0; i < cycles; i++)
		{
			plain->updateGrid();
		}
		
		std::cout << "Final Plain:" << std::endl <<
					 plain->gridToString() << std::endl;
	
		char save; 
		std::cout << "Do you want to save this plain (y/n): ";
		std::cin >> save;


		if(save == 'y' || save == 'Y')
		{
			std::cout << "Enter File Name: ";
			std::cin >> fileName;
			plain->write(fileName);
		}

		trial++;
		delete plain;
	}

	return 0;
}
