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
	//std::cout << "Int constructor called" << std::endl;
	_fixedVal = val << _fractional;
}

//float constructor

Fixed::Fixed(float val)
{
	//std::cout << "Float constructor called" << std::endl;
	_fixedVal = roundf(val * (1 <<_fractional));
}


Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& val)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_fixedVal = val._fixedVal;
}

Fixed& Fixed::operator=(const Fixed& val)
{
	//std::cout << "Copy assignment operator called" << std::endl;
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

/***OVERLOADS***/

//overload "<<"

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

//comparison overloads

bool Fixed::operator>( const Fixed& val ) const
{
	return (this->_fixedVal > val._fixedVal);
}

//for bsp
bool Fixed:: operator>( const int val) const
{
	return (this->_fixedVal > val * (1 << _fractional));
}

bool Fixed::operator<( const Fixed& val ) const
{
	return (this->_fixedVal < val._fixedVal);
}

bool Fixed::operator<=( const Fixed& val ) const
{
	return (this->_fixedVal <= val._fixedVal);
}

bool Fixed::operator>=( const Fixed& val ) const
{
	return (this->_fixedVal >= val._fixedVal);
}

bool Fixed::operator==( const Fixed& val ) const
{
	return (this->_fixedVal == val._fixedVal);
}

bool Fixed::operator!=( const Fixed& val ) const
{
	return (this->_fixedVal != val._fixedVal);
}

//arithmetic operators

Fixed Fixed::operator+( const Fixed& val ) const
{
	return Fixed(this->toFloat() + val.toFloat());
}

Fixed Fixed::operator-( const Fixed& val ) const
{
	return Fixed(this->toFloat() - val.toFloat());
}

Fixed Fixed::operator*( const Fixed& val ) const
{
	return Fixed(this->toFloat() * val.toFloat());
}

Fixed Fixed::operator/( const Fixed& val ) const
{
	return Fixed(this->toFloat() / val.toFloat());
}

//increment/decrement operators

Fixed& Fixed::operator++( void )
{
	++_fixedVal;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed temp(*this);
	++_fixedVal;
	return (temp);
}

Fixed& Fixed::operator--( void )
{
	--_fixedVal;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed temp(*this);
	--_fixedVal;
	return (temp);
}

//min/max

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a._fixedVal < b._fixedVal)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._fixedVal < b._fixedVal)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a._fixedVal > b._fixedVal)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._fixedVal > b._fixedVal)
		return (a);
	return (b);
}
