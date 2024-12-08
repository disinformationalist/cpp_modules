#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedVal = 0;
}

//const int constructor

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedVal = val << _fractional;
}

//float constructor

Fixed::Fixed(float val)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedVal = roundf(val * (1 <<_fractional));
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& val)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedVal = val._fixedVal;
}

Fixed& Fixed::operator=(const Fixed& val)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &val)
		this->_fixedVal = val.getRawBits();
	return (*this);
}

// returns raw value of the fixed point value

int	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fixedVal);
}

// sets the raw value of the fixed-point number

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	_fixedVal = raw;
}

//converts fixed point representation to float

float Fixed::toFloat( void ) const
{
	return(static_cast<float>(_fixedVal) / (1 << _fractional));
}

//fixed point to integer

int	Fixed::toInt( void ) const
{
	return (_fixedVal >> _fractional);
}

//overload "<<"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}