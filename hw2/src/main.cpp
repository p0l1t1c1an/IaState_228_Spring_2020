
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "PointScanner.hpp"

static const int POINT_RANGE = 101; // the range of points x and y coords 
								  // subtracted by 50 to have -50 - 50 range

static Point* random_points(int num_pts)	
{
	if(num_pts < 1)
	{
		throw std::invalid_argument("Invalid Length Of Point Array");
	}

	Point* p_arr = new Point[num_pts];
	
	int i;
	for(i = 0; i < num_pts; ++i)
	{
		int x = rand() % POINT_RANGE - 50;
		int y = rand() % POINT_RANGE - 50;
		
		p_arr[i] = Point(x, y);
	}

	return p_arr;  
}

int main(void)	
{		
	int trials = 0, input = 0;

	std::vector<PointScanner> scanners;

	srand(time(NULL));

	std::cout << "Performances of Four Sorting Algorithms in Point Scanning" << std::endl <<
					   "keys: 1 (random integers) 2 (file input) 3 (exit)" << std::endl << std::endl;

	while(input != 3) // Entering 3 quits
	{
		std::cout << "Trial " << trials << ": ";

		std::cin >> input;

		if(input == 1) // Random Points
		{
			std::cout << "Randon Points" << std::endl << "Enter the number of random points: ";
			
			int num_pts;	
			std::cin >> num_pts;

			Point* p_arr = random_points(num_pts);

			// iterates through each value of in Algorithm enum
			int i;
			for(i = 0; i < TOTAL_ALGORITHMS; ++i)
			{
				scanners.push_back(PointScanner(p_arr, num_pts, i));
			}

			delete p_arr; 
		}	
		else if(input == 2) // Points from a file
		{
			std::cout << "Points from a file" << std::endl << "Enter the file name: ";
			
			std::string file;
			std::cin >> file;
			
			int i;
			for(i = 0; i < TOTAL_ALGORITHMS; ++i)
			{
				scanners.push_back(PointScanner(file, i));	
			}
		}
		else if(input == 3) // Quit
		{
			continue; // Back to while loop condition
		}
		else
		{
			std::cout << "Invalid input." << std::endl << "Enter a number from 1 - 3." << std::endl;
			
			std::cin.clear();
			std::cin.ignore(10000,'\n');

			continue;
		}
	
		std::cout << "algorithm size time (ns)" << std::endl;
		
		for(PointScanner& ps : scanners) // Paper and Scissors, but no Rock
		{
			//std::cout << ps.to_string();
			ps.scan();	
			ps.draw();
			std::cout << ps.stats();
			//std::cout << ps.to_string();
			//ps.write_to_file(); // Uncomment to test writing
		}
	
		std::cout << std::endl;
		scanners.clear();
		trials++;
	}
}

