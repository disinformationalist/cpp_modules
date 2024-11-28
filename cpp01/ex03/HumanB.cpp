#include "HumanB.hpp"

HumanB::HumanB(str name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (_weapon == NULL || _weapon->getType() == "")
		std::cout << _name << " is unarmed and attacks verbally" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; 
}

void	HumanB::setWeapon(Weapon& weap)
{
	_weapon = &weap;
}