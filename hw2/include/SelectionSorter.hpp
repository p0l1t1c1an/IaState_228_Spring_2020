
#pragma once
#include "AbstractSorter.hpp"

class SelectionSorter : public AbstractSorter
{
	public: 

		SelectionSorter(std::vector<Point>& pts);
		
		~SelectionSorter();

		void sort();
};
