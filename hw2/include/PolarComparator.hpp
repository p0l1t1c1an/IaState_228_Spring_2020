
#pragma once
#include "Point.hpp"

class PolarComparator
{
	public:	
		static Point ref_point; // reference const Point for polar angle comparison 

		static int compare(Point& p1, Point& p2); // uses both compare_polar and compare_pistance

	private:
		static int compare_polar(Point& p1, Point& p2); // returns false if p1 angle is smaller
		
		static int compare_distance(Point& p1, Point& p2); // returns false if p1 distance is smaller
		
		static int cross_product(Point& p1, Point& p2); 
	 
		static int dot_product(Point& p1, Point& p2);
};
