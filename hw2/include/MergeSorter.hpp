
#pragma once
#include "AbstractSorter.hpp"

class MergeSorter : public AbstractSorter
{
	public:
		MergeSorter(std::vector<Point>& pts);

		~MergeSorter();
		
		void sort();

	private:
		void merge_sort_rec(std::vector<Point>& pts);

		void merge(std::vector<Point>& pts, std::vector<Point>& sub1, std::vector<Point>& sub2);
};
