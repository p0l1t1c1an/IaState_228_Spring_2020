
#pragma once
#include "Living.hpp"

class Animal : public Living
{
	protected:
		int age;   // age of the animal 
    
	public:
		Animal(struct Point p, int a) : Living(p), age(a) {}		
		~Animal(){}	

		int myAge()
		{
			return age; 
		}
};

