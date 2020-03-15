
#pragma once
#include "Point.hpp"

class Segment 
{
	public:
		Segment(Point& p1, Point& p2);
	
		Point& get_p1();
	
		Point& get_p2();

	private:
		Point p1, p2; 
};
