
#include "Point.hpp" 
		
bool Point::xORy = true;

Point::Point() : x(0), y(0){}  // default constructor

Point::Point(int x_in, int y_in) : x(x_in), y(y_in) {}

Point::Point(const Point& p) : x(p.x), y(p.y) {} // copy constructor

int Point::get_x()   
{
	return x;
}

int Point::get_y()
{
	return y;
}	

bool Point::operator == (const Point& p2)
{
	return this->x == p2.x && this->y == p2.y;   
}

bool Point::operator < (const Point p2)
{
	if(xORy) 
	{
		if(this->x < p2.x || (this->x == p2.x && this->y < p2.y))
		{
			return true;
		}
	}
	else 
	{
		if(this->y < p2.y || (this->y == p2.y && this->x < p2.x))
		{
			return true;
		}
	}

	return false;
}

std::string Point::to_string() 
{
	std::string str = "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
	return str; 
}
