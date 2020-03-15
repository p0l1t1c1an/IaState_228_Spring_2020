
#include <fstream>
#include "Plot.hpp"

static const int MIN_POINT = -50;
static const int MAX_POINT = 50;
static const double TICK_LENGTH = .5;
static const double LINE_WIDTH = .5;
static const double POINT_WIDTH = .15;

void Plot::draw(std::vector<Point>& pts, std::vector<Segment>& segs, std::string& output_file)
{
	std::ofstream file(output_file);

	PlotterParams param;
	param.setplparam("BITMAPSIZE", (char* )"750x750");
	
	PNGPlotter plot(std::cin, file, std::cerr, param);
    if (plot.openpl() < 0)
    {
		std::cerr << "PNGPlotter failed to open" << std::endl;
		return;
	}

	plot.erase();

	draw_axis(plot);

	plot.flinewidth(LINE_WIDTH); 
	plot.pencolor(5000, 5000, 50000); // range is 0 - 65535
	
	int i;
	for(i = 0; i < segs.size(); ++i)
	{
		Point& p1 = segs[i].get_p1();
		Point& p2 = segs[i].get_p2();

		plot.line(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
	}

	plot.flinewidth(LINE_WIDTH *1.5); 
	plot.pencolor(50000, 5000, 5000);
	
	for(i = 0; i < pts.size(); ++i)
	{ 
		plot.fcircle(pts[i].get_x(), pts[i].get_y(), POINT_WIDTH);
	}

	if (plot.closepl() < 0)
    {
		std::cerr << "PNGPlotter failed to close" << std::endl;
    }
}

void Plot::draw_axis(Plotter& plot)
{
	plot.flinewidth(LINE_WIDTH / 2);
	plot.space(MIN_POINT, MIN_POINT, MAX_POINT, MAX_POINT);

	plot.line(MIN_POINT, 0, MAX_POINT, 0);
	plot.line(0, MIN_POINT, 0, MAX_POINT);

	int i;
	plot.pencolor(0, 0, 0);
	for(i = MIN_POINT; i < MAX_POINT; ++i)
	{
		plot.fline(-TICK_LENGTH, i, TICK_LENGTH, i);
		plot.fline(i, -TICK_LENGTH, i, TICK_LENGTH);
	}
}
