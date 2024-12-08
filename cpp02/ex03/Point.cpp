#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point( const float x, const float y ) : _x(Fixed(x)), _y(Fixed(y)) 
{
}

Point::Point( const Point& val) : _x(val.getX()), _y(val.getY())
{}

Point& Point::operator=( const Point& val )
{
	if (this != &val)
	{
		( Fixed )this->_x = val.getX();
		( Fixed )this->_y = val.getY();
	}
	return (*this);
}

Point::~Point()
{}

//getters

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

