#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
			HumanB( str name );
			~HumanB();
	void	attack( void );
	void	setWeapon ( Weapon& weap );
private:
	str		_name;
	Weapon*	_weapon;
};

#endif