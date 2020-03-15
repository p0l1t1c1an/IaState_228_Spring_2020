
#include <stdexcept>
#include <iterator>
#include <vector>

#include "AbstractSorter.hpp"

void AbstractSorter::set_comparator(int order) 
{
	if(order == 2)
	{
		using_polar = true;
	}
	else if(order == 1)
	{
		Point::xORy = false;
		using_polar = false;
	}
	else if(order == 0)
	{
		Point::xORy = true;
		using_polar = false;
	}
}


Point AbstractSorter::get_median()
{
	return points[points.size()/2]; 
}

std::vector<Point> AbstractSorter::get_points()
{
	return points; 
}

AbstractSorter::~AbstractSorter() {}

AbstractSorter::AbstractSorter(std::vector<Point>& pts)
{
	if(pts.size() <= 0)
	{
		throw std::invalid_argument("Abstract Sorter: Invalid length");
	}

	points = pts;
}

void AbstractSorter::swap(int i, int j)
{
	Point temp = points[i];
	points[i] = points[j];
	points[j] = temp;
}	
