#include "Animal.hpp"

/***constructors, destructors***/

Animal::Animal() :_type("Unspecified animal")
{
	std::cout << "Animal: " << _type << " Constructor has been called" << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "Animal: " << _type << " Constructor has been called" << std::endl;
}

Animal::Animal( const Animal &other )
{
	std::cout << "Animal Copy Constructor has been called" << std::endl;
	*this = other;
}

Animal& Animal::operator=( const Animal& other )
{
	std::cout << "Animal Assignment operator has been called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor has been called" << std::endl;
}

/**member functions**/

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "Random animal sound" << std::endl;
}

Brain* Animal::getBrain() const
{
	return (NULL);	
}
