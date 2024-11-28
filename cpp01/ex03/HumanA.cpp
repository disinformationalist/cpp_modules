#include "HumanA.hpp"

HumanA::HumanA( str name, Weapon& weap)
	: _name(name), _weapon(weap)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void )
{
	if (_weapon.getType() == "")
		std::cout << _name << " is unarmed and attacks with interpretive dance" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void	HumanA::setWeapon( Weapon weap)
{
	_weapon = weap;
}