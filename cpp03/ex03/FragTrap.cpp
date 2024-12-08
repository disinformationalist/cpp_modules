#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name) : ClapTrap (name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap (other)
{
	std::cout << "Frag Copy Constructor has been called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Frag Copy assignment operator has been called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "Fragtrap " << _name << " requests the highest of fives" << std::endl;
}
