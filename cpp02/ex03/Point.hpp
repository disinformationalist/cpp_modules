#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
					Point();
					Point( const float x, const float y );
					Point( const Point& val );
					~Point();
			Point&	operator=( const Point& val );
		 	Fixed	getX() const;
		 	Fixed	getY() const;

private:
	const Fixed _x;
	const Fixed _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif