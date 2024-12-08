#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedVal = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fractional)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedVal = fractional._fixedVal;
}

Fixed& Fixed::operator=(const Fixed& fractional)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fractional)
		this->_fixedVal = fractional.getRawBits();
	return (*this);
}

// returns raw value of the fixed point value
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedVal);
}

// sets the raw value of the fixed-point number

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedVal = raw;
}