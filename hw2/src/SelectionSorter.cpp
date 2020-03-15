
#include "SelectionSorter.hpp"

SelectionSorter::SelectionSorter(std::vector<Point>& pts) : AbstractSorter(pts) {}	

SelectionSorter::~SelectionSorter() {}	

void SelectionSorter::sort()
{
	int i, j;
	for(i = 0; i < points.size(); ++i)
	{
		int smallest = i;
		for(j = i; j < points.size(); ++j)
		{
			int compare_int = 0;

			if(using_polar)
            {
                compare_int = PolarComparator::compare(points[smallest], points[j]);
            }
            else
            {
				if(points[j] < points[smallest])
				{	
					compare_int = 1;
				}
            }

			if(compare_int > 0) // smaller point at j than at smallest
			{
				smallest = j;
			}
		}
		swap(smallest, i);
	}
}
