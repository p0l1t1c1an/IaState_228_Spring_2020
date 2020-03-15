
#include "Segment.hpp"

Segment::Segment(Point& p1, Point& p2)
{
	this->p1 = p1; 
	this->p2 = p2; 
}
	
Point& Segment::get_p1()
{
	return p1; 
}
	
Point& Segment::get_p2()
{
	return p2; 
}

