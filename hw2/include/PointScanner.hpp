
#pragma once

#include "InsertionSorter.hpp"
#include "SelectionSorter.hpp"
#include "MergeSorter.hpp"
#include "QuickSorter.hpp"

class PointScanner  
{
	private: 
		std::vector<Point> points; 
		
		Point median_point;  // point whose x and y coordinates are respectively the medians of 
											  // the x coordinates and y coordinates of those points in the array points[].

		std::string output_file;   // "select.txt", "insert.txt", "merge.txt", or "quick.txt"
		
		int algo;
		long scan_time;

	public:

		PointScanner(Point pts[], int len, int algo);

		PointScanner(std::string& inputFileName, int algo);

		void scan();

		std::string stats();

		std::string to_string();

		void write_to_file();

		void draw();
};
