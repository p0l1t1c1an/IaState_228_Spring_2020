
#include "MergeSorter.hpp"

MergeSorter::MergeSorter(std::vector<Point>& pts) : AbstractSorter(pts) {}

MergeSorter::~MergeSorter() {}

void MergeSorter::sort()
{
	 merge_sort_rec(points);
}


void MergeSorter::merge_sort_rec(std::vector<Point>& pts)
{
	if(pts.size() <= 1)
	{
		return;
	}

	std::vector<Point>::const_iterator mid = pts.begin() + pts.size()/2;

	std::vector<Point> left(pts.cbegin(), mid);
	std::vector<Point> right(mid, pts.cend()); 
	
	merge_sort_rec(left);
	merge_sort_rec(right);

	merge(pts, left, right);
}


void MergeSorter::merge(std::vector<Point>& pts, std::vector<Point>& sub1, std::vector<Point>& sub2)
{
	// counts for both sub-arrays values being used 
	// and the total count
	int c1 = 0, c2 = 0, total = 0;
	
	while(total < sub1.size() + sub2.size())
	{
		if(c1 >= sub1.size())
		{
			pts[total] = sub2[c2];
			++c2;
		}
		
		else if(c2 >= sub2.size())
		{
			pts[total] = sub1[c1];
			++c1;
		}
	
		else
		{
			int compare_int;
			if(using_polar)
			{
				compare_int = PolarComparator::compare(sub1[c1], sub2[c2]);
			}
			else
			{
				if(sub1[c1] < sub2[c2])
				{
					compare_int = -1;
				}
				else if(sub1[c1] == sub2[c2])
				{
					compare_int = 0;
				}
				else
				{
					compare_int = 1;
				}
			}

			if(compare_int < 0 || compare_int == 0) //sub1 is smaller or equal to sub2
			{
				pts[total] = sub1[c1];
				++c1;
			}
			else
			{
				pts[total] = sub2[c2];
				++c2;
			}
		}
		++total;
	}
}

