#include "Cat.hpp"

/***constructors, destructors***/

Cat::Cat() : Animal::Animal("Cat")
{
	_type = "Cat";
	std::cout << "Cat Constructor has been called" << std::endl;
	_brain = new Brain();
}

Cat::Cat( const Cat& other) : Animal::Animal(other)
{
	std::cout << "Cat Copy Constructor has been called" << std::endl;
	//deep coping
	_brain = new Brain(*other._brain);
}

Cat&	Cat::operator=( const Cat& other )
{
	std::cout << "Cat Assignment operator has been called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor has been called" << std::endl;
	delete _brain;
}

/**member functions**/

void Cat::makeSound() const
{
	std::cout << "Roar" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (_brain);	
}