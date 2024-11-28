#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}

void	Zombie::setName( str name )
{
	_name = name;
}

void	Zombie::announce( void ) const
{
	std::cout << "We are the " << _name << std::endl;
}