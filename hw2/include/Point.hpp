
#pragma once
#include <string>

class Point
{
	public: 
		
		static bool xORy;  // compare x coordinates if xORy == true and y coordinates otherwise  

		Point();  // default constructor
		
		Point(int x, int y);
		
		Point(const Point& p);  // copy constructor

		int get_x();
		
		int get_y();

		bool operator == (const Point& p2);

		bool operator < (const Point p2);

		std::string to_string();

	private:
		int x, y;
};
