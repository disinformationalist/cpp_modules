#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap& other);	
	ClapTrap&	operator=(const ClapTrap& other);	
				~ClapTrap();

	std::string		getName();
	unsigned int	getHitPoints();
	unsigned int	getAttackDamage();
	void			setAttackDamage(unsigned int damage);


	void		attack( const std::string& target);
	void		takeDamage( unsigned int amount );
	void		beRepaired (unsigned int amount );		

protected:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif// CLAPTRAP_HPP