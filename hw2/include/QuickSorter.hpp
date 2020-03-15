
#pragma once
#include "AbstractSorter.hpp"

class QuickSorter : public AbstractSorter
{
	public:

		QuickSorter(std::vector<Point>& pts);
		
		~QuickSorter();
	
		void sort();
	
	private:
		void quick_sort_rec(int first, int last);
	
		int partition(int first, int last);
};
