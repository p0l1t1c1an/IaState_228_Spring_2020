
#include "InsertionSorter.hpp"

InsertionSorter::InsertionSorter(std::vector<Point>& pts) : AbstractSorter(pts) {}	

InsertionSorter::~InsertionSorter() {}	

void InsertionSorter::sort()
{	
	int i, j;
	for(i = 0; i < points.size(); ++i)
	{	
		Point temp = points[i];
		for(j = i-1; j >= 0; --j)
		{
			int compare_int = 0;

			if(using_polar)
			{
				compare_int = PolarComparator::compare(temp, points[j]);
			}
			else
			{
				if(temp < points[j])
				{
					compare_int = -1;
				}
			}

			if(compare_int < 0) //temp is smaller
			{
				points[j+1] = points[j];
			}
			else
			{
				break;
			}
		}
		points[j+1] = temp;
	}
}


