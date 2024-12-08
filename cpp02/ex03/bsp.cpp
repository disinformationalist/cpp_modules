#include "Point.hpp"

/* a,b,c = verts of triangle, point = point to check, 
true if in triangle, false if on edge, vertex, or outside. */


/* each edge is a binary partition, if inside all 3 edges, is in the tri */


//dist scaled by edge length from point to line, sign determines which side.
//using cross product here

Fixed	signedDist(const Point& point, const Point& edgeStart, const Point& edgeEnd)
{	
	return ((point.getX() - edgeStart.getX()) * (edgeEnd.getY() - edgeStart.getY()) -
	(point.getY() - edgeStart.getY()) * (edgeEnd.getX() - edgeStart.getX()));
}

//keeping everything in the scaled fixed point "should" be faster than float

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = signedDist(point, a, b);
	Fixed d2 = signedDist(point, b, c);
	Fixed d3 = signedDist(point, c, a);

	return ((d1 > 0) && (d2 > 0) && (d3 > 0)) || ((d1 < 0) && (d2 < 0) && (d3 < 0));
}
