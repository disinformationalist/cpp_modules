#include "WrongCat.hpp"

/***constructors, destructors***/

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WrongCat")
{
	_type = "WrongCat";
	std::cout << "WrongCat Constructor has been called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other) : WrongAnimal::WrongAnimal(other.getType())
{
	std::cout << "WrongCat Copy Constructor has been called" << std::endl;
	*this = other;
}

WrongCat&	WrongCat::operator=( const WrongCat& other )
{
	std::cout << "WrongCat Assignment operator has been called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor has been called" << std::endl;
}

/**member functions**/

void WrongCat::makeSound() const
{
	std::cout << "Wrong Roar" << std::endl;
}