
#pragma once
#include <vector>
#include "PolarComparator.hpp"

enum Algorithms 
{
	SELECTION, INSERTION, MERGE, QUICK, TOTAL_ALGORITHMS
};

class AbstractSorter
{
	private:
		Point ref; 	 // common reference point for computing the polar angle 

	public:
		virtual void sort() = 0; 

		void set_comparator(int order);

		Point get_median();

		std::vector<Point> get_points();

		virtual ~AbstractSorter();

	protected:
		std::vector<Point> points;  // array of points operated on by a sorting algorithm. 
		// stores ordered points after a call to sort(). 

		bool using_polar = false;	// tracker if using PolarComparator 

		AbstractSorter(std::vector<Point>& pts);

		void swap(int i, int j);	
};
