#include "Dog.hpp"

/***constructors, destructors***/

Dog::Dog() : Animal::Animal("Dog")
{
	std::cout << "Dog Constructor has been called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog( const Dog& other) :Animal(other)
{
	std::cout << "Dog Copy Constructor has been called" << std::endl;
	//deep coping
	_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "Dog Assignment operator has been called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor has been called" << std::endl;
	delete _brain;
}

/**member functions**/

void Dog::makeSound() const
{
	std::cout << "Ruff" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (_brain);	
}