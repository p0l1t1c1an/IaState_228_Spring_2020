
#pragma once
#include "AbstractSorter.hpp"

class InsertionSorter : public AbstractSorter
{
	public:
		InsertionSorter(std::vector<Point>& pts);		

		~InsertionSorter();		

		void sort();
};
