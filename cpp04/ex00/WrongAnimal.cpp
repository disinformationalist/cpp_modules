#include "WrongAnimal.hpp"

/***constructors, destructors***/

WrongAnimal::WrongAnimal() :_type("Unspecified WrongAnimal")
{
	std::cout << "WrongAnimal: " << _type << " Constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "WrongAnimal: " << _type << " Constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
	std::cout << "WrongAnimal Copy Constructor has been called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	std::cout << "WrongAnimal Assignment operator has been called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor has been called" << std::endl;
}

/**member functions**/

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random WrongAnimal sound" << std::endl;
}
