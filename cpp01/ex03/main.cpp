#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main( void )
{
	//A init, attack, change type, attack
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	//B init, set weapon, attack, change type attack
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	//A init with empty type weapon, attack
	{
		Weapon club = Weapon("");

		HumanA bob("Bob", club);
		bob.attack();
	}

	//B init no weapon(==NULL), attack
	{
		HumanB jim("Jim");
		jim.attack();
	}
	return (0);
}