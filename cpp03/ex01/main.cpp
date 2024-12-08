#include "ScavTrap.hpp"

int main()
{
	ScavTrap	Scav1("Scav1");
	ScavTrap	Todd("Todd");

	//scav1 attacks
	Scav1.setAttackDamage(3);
	Scav1.attack("Todd");
	
	//take damage is still the inherited function, so the clap Todd gets the damage
	Todd.takeDamage(Scav1.getAttackDamage());
	Todd.beRepaired(1);
	
	//todd attacks
	Todd.setAttackDamage(1);
	Todd.attack("Scav1");
	
	
	Scav1.takeDamage(Todd.getAttackDamage());

	Todd.guardGate();
	Scav1.guardGate();

	return (0);
}