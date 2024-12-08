#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name) : ClapTrap (name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap (other), FragTrap(other), ScavTrap(other)
{
	std::cout << "Diamond Copy Constructor has been called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Diamond Copy assignment operator has been called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " << _name << " and my Claptraps name is " << ClapTrap::_name << std::endl;
}