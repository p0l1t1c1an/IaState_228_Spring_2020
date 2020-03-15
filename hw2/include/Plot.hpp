
#pragma once
#include <plotter.h> 
#include <vector>

#include "Segment.hpp"

class Plot {
	
	public:

		static void draw(std::vector<Point>& pts, std::vector<Segment>& segs, std::string& title);

	private:

		static void draw_axis(Plotter& plot);
};
