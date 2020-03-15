
#include <iterator>
#include <stdexcept>
#include <fstream>
#include <chrono>

#include "PointScanner.hpp"
#include "Plot.hpp"

PointScanner::PointScanner(Point pts[], int len, int algo)
{
	if(pts == NULL)
	{
		throw std::invalid_argument("Invalid Point Array Size");
	}

	for(int i = 0; i < len; ++i)
	{
		points.push_back(Point(pts[i]));
	}

	this->algo = algo;

	switch(algo)
	{
		case SELECTION:
			output_file = "select.txt";
			break;

		case INSERTION:
			output_file = "insert.txt";
			break;

		case MERGE:
			output_file = "merge.txt";
			break;

		case QUICK:
			output_file = "quick.txt";
			break;

		default:
			throw std::invalid_argument("Invalid Algorithm Type");
	}
}

PointScanner::PointScanner(std::string input_file, int algo)
{
	std::ifstream file(input_file);

	int temp, count; 
	while(file >> temp)
	{
		count++;
	}

	if(count % 2 != 0)
	{
		throw std::length_error("Input File Contains Odd Number Of Integers");
	}

	file.clear();
	file.seekg(0, std::ios::beg);

	count = 0;
	while(file)
	{ 
		int x, y;
		file >> x;
		file >> y;

		this->points.push_back(Point(x ,y)); 
	}

	this->algo = algo;

	switch(algo)
	{
		case SELECTION:
			output_file = "select.txt";
			break;

		case INSERTION:
			output_file = "insert.txt";
			break;

		case MERGE:
			output_file = "merge.txt";
			break;

		case QUICK:
			output_file = "quick.txt";
			break;

		default:
			throw new std::invalid_argument("Invalid Algorithm Type");
	}
}


static auto current_time()
{
	using namespace std::chrono;
	return duration_cast< nanoseconds > (
		system_clock::now().time_since_epoch());
}

void PointScanner::scan()
{
	AbstractSorter* a_sorter;

	switch(this->algo)
	{
		case SELECTION:
			a_sorter = new SelectionSorter(points);
			break;

		case INSERTION:
			a_sorter = new InsertionSorter(points);
			break;

		case MERGE:
			a_sorter = new MergeSorter(points);
			break;

		case QUICK:
			a_sorter = new QuickSorter(points);
			break;
	}

	int med_x, med_y;

	auto start = current_time();

	a_sorter->set_comparator(0);
	a_sorter->sort();

	med_x = a_sorter->get_median().get_x();

	a_sorter->set_comparator(1);
	a_sorter->sort();

	med_y = a_sorter->get_median().get_y();

	median_point = Point(med_x, med_y);

	PolarComparator::ref_point = median_point;
	a_sorter->set_comparator(2);
	a_sorter->sort();

	points = a_sorter->get_points();

	this->scan_time = current_time().count() - start.count();

	delete a_sorter;
}
	
std::string PointScanner::stats()
{
	std::string sort = "";

	switch(this->algo)
	{
		case SELECTION: 
			sort = "Selection Sort"; 
			break; 
		
		case INSERTION: 
			sort = "Insertion Sort"; 
			break; 
		
		case MERGE: 
			sort = "Mergesort"; 
			break; 
	
		case QUICK: 
			sort = "Quicksort"; 
			break; 
	}

	return sort + '\t' + std::to_string(points.size()) + '\t' + std::to_string(scan_time) + '\n'; 
}
	
std::string PointScanner::to_string()
{
	std::string p_string = std::to_string(median_point.get_x()) + " " + std::to_string(median_point.get_y()) + "\n";
	
	for(Point& p : this->points)
	{
		p_string += std::to_string(p.get_x()) + " " + std::to_string(p.get_y()) + "\n";
	}

	return p_string; 
}

void PointScanner::write_to_file()
{
	std::ofstream file(this->output_file);

	file << this->to_string();
}	

void PointScanner::draw()
{		
	std::vector<Segment> segments; 

	int i; 
	for(i = 0; i < points.size(); ++i)
	{
		int next = (i+1) % points.size();
		if(!(points[i] == points[next]))
		{
			segments.push_back(Segment(points[i], points[next]));
		}
		segments.push_back(Segment(points[i], median_point));
	}

	std::string sort = ""; 
	
	switch(this->algo)
	{
		case SELECTION: 
			sort = "SelectionSort.png"; 
			break; 
		case INSERTION: 
			sort = "InsertionSort.png"; 
			break; 
		case MERGE: 
			sort = "MergeSort.png"; 
			break; 
		case QUICK: 
			sort = "QuickSort.png"; 
			break; 
		default: 
			break; 		
	}

	// The following statement creates a window to display the sorting result.
	Plot::draw(points, segments, sort);	
}	
