#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name) : ClapTrap (name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap (other)
{
	std::cout << "Scav Copy Constructor has been called" << std::endl;
	*this = other;
}


ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Scav Copy assignment operator has been called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack( const std::string& target)
{
		if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is dead and cannot attack" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy points and cannot attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " 
			  << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}
