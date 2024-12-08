#include "Point.hpp"

int main( void )
{
	//assign point values in x and y.
	//verts
	Point a(0, 0);
	Point b(6, 1);
	Point c(3, 6);
	
	//test points
	Point p1(3, 2); //in
	Point p2(6, 1); //on vert(out)
	Point p3(5, 3); //out
	Point p4(1, 2); //edge(out)
	
	Point points[4] = { p1, p2, p3, p4};

	//check all
	for (int i = 0; i < 4; i++)
	{
		const Point& point = points[i];
		if (bsp(a, b, c, point))
			std::cout << "Point is within triangle" << std::endl;
		else
			std::cout << "Point is not within triangle" << std::endl;
	}
	return (0);
}