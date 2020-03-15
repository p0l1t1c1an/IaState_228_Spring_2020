
#include "QuickSorter.hpp"

QuickSorter::QuickSorter(std::vector<Point>& pts) : AbstractSorter(pts) {}
	
QuickSorter::~QuickSorter() {}

void QuickSorter::sort()
{
	quick_sort_rec(0, points.size()-1); 
}

void QuickSorter::quick_sort_rec(int first, int last)
{
	if(first < last)
	{
		int part = partition(first, last);
		
		quick_sort_rec(first, part-1);
		quick_sort_rec(part+1, last);
	}
}

int QuickSorter::partition(int first, int last)
{
	Point pivot = points[last];

	int i = first -1, j;

	for(j = first; j < last; ++j)
	{
		int compare_int = 0;
		if(using_polar)
		{
			compare_int = PolarComparator::compare(pivot, points[j]);
		}
		else
		{
			if(points[j] < pivot)
			{
				compare_int = 1;
			}
		}

		if(compare_int > 0) //pivot is larger
		{
			++i;
			swap(i, j);
		}
	}
	swap(++i, last);
	return i; 
}	
