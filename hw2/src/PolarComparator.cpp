
#include "PolarComparator.hpp"

Point PolarComparator::ref_point;

int PolarComparator::compare(Point& p1, Point& p2)
{
	int pa = compare_polar(p1, p2);

	if(pa == 0)
	{
		return compare_distance(p1, p2);
	}
	
	return pa;
}

int PolarComparator::compare_polar(Point& p1, Point& p2) 
{	
	if(p1.get_y() == ref_point.get_y()) 
	{
		if(p2.get_y() == ref_point.get_y()) // are both on x axis?
		{
			if(p1.get_x() > ref_point.get_x() && p2.get_x() > ref_point.get_x()) // both to the right?
			{
				return 0;
			}
			else if(p1.get_x() > ref_point.get_x()) 
			{
				return -1;
			}
			else 
			{
				return 1;
			}
		}
		else if(p1.get_x() > ref_point.get_x()) 
		{
			return -1;
		}
	}

	if(p2.get_y() == ref_point.get_y() && p2.get_x() > ref_point.get_x()) 
	{
		return 1;
	}

	// if p1 is above the reference and p2 is below
	if(p1.get_y() > ref_point.get_y() && p2.get_y() < ref_point.get_y()) 
	{
		return -1;
	}
	
	if(p1.get_y() < ref_point.get_y() && p2.get_y() > ref_point.get_y()) 
	{
		return 1; 
	}

	//  Points must be in the same half so we can 
	// return based on the direction of the cross product 

    int c = cross_product(p1, p2);

	if(c > 0)  // positive means p1 is before p2
	{
		return -1;
	}

	if(c < 0)
	{
		return 1;
	}

	return 0; 
}

int PolarComparator::compare_distance(Point& p1, Point& p2)
{
	int d1 = dot_product(p1, p1); // dot product with the same point is distance squared
	int d2 = dot_product(p2, p2);
	
	if(d1 == d2)
	{
		return 0;
	}
	else if(d1 < d2)
	{
		return -1;
	}

	return 1;
}

int PolarComparator::cross_product(Point& p1,  Point& p2)
{
    int x1, x2, y1, y2;
	x1 = p1.get_x() - ref_point.get_x();
	x2 = p2.get_x() - ref_point.get_x();
	y1 = p1.get_y() - ref_point.get_y();
	y2 = p2.get_y() - ref_point.get_y();

    return x1*y2 - x2*y1; 
}

int PolarComparator::dot_product(Point& p1, Point& p2)
{
    int x1, x2, y1, y2;
	x1 = p1.get_x() - ref_point.get_x();
	x2 = p2.get_x() - ref_point.get_x();
	y1 = p1.get_y() - ref_point.get_y();
	y2 = p2.get_y() - ref_point.get_y();
    
	return x1*x2 + y1*y2; 
}
