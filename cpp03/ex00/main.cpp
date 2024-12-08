#include "ClapTrap.hpp"

int main()
{
	ClapTrap	Akbar("Akbar");
	ClapTrap	Grievous("Grievous");

	//ak attacks
	Akbar.setAttackDamage(3);
	Akbar.attack("Grievous");
	Grievous.takeDamage(Akbar.getAttackDamage());
	Grievous.beRepaired(1);
	
	//gri attacks
	Grievous.setAttackDamage(9);
	Grievous.attack("Akbar");
	Akbar.takeDamage(Grievous.getAttackDamage());

	//ak repair until energy exhausted
	for (int i = 0; i < 9; i++)
	{
		Akbar.beRepaired(1);
	}

	//ak cant do anything without energy
	Akbar.beRepaired(1);
	Akbar.attack("Grievous");
	
	//gri kills ak
	Grievous.setAttackDamage(15);
	Grievous.attack("Akbar");
	Akbar.takeDamage(Grievous.getAttackDamage());

	
	//ak is dead and cant do things
	Akbar.beRepaired(1);
	Akbar.attack("Grievous");

	return (0);
}