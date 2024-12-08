#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	Dia1("Dia1");
	DiamondTrap	Todd("Todd");

	//Dia1 attacks
	Dia1.setAttackDamage(3);
	Dia1.attack("Todd");
	
	Todd.takeDamage(Dia1.getAttackDamage());

	//try unique inhereted fts
	Todd.highFivesGuys();
	Dia1.highFivesGuys();
	
	Todd.whoAmI();
	Dia1.whoAmI();
	return (0);
}