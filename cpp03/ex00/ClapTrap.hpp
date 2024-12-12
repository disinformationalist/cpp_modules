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

	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getAttackDamage() const;
	void			setAttackDamage(unsigned int damage);


	void		attack( const std::string& target);
	void		takeDamage( unsigned int amount );
	void		beRepaired (unsigned int amount );		

private:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif// CLAPTRAP_HPP