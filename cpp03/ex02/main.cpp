#include "FragTrap.hpp"

int main()
{
	FragTrap	Frag1("Frag1");
	FragTrap	Todd("Todd");

	//Frag1 attacks
	Frag1.setAttackDamage(3);
	Frag1.attack("Todd");
	
	//take damage is still the inherited function, so the clap Todd gets the damage
	Todd.takeDamage(Frag1.getAttackDamage());
	Todd.beRepaired(1);
	
	//todd attacks
	Todd.setAttackDamage(1);
	Todd.attack("Frag1");
	
	
	Frag1.takeDamage(Todd.getAttackDamage());

	Todd.highFivesGuys();
	Frag1.highFivesGuys();

	return (0);
}