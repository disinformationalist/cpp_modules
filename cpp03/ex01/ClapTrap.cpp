#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Clap Copy Constructor has been called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Clap Copy assignment operator has been called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

/***get and set***/

std::string	ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

void		ClapTrap::setAttackDamage(unsigned int damage)
{
	_attackDamage = damage;
}

/***actions***/

void		ClapTrap::attack( const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points and cannot attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << " causing " 
			  << _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void		ClapTrap::takeDamage( unsigned int amount )
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot take damage" << std::endl;
		return ;
	}
	if (_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << _name << " has died" << std::endl;
		_hitPoints = 0;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage" 
			  << std::endl;
	_hitPoints -= amount;
}

void		ClapTrap::beRepaired (unsigned int amount )
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot repair" << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points and cannot repair" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs " << amount << " points " 
			  << std::endl;
	_hitPoints += amount;
	_energyPoints -= 1;
}