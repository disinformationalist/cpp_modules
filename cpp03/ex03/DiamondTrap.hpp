#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
					DiamondTrap( std::string name );
					DiamondTrap(const DiamondTrap& other);
	DiamondTrap&	operator=(const DiamondTrap& other);
					~DiamondTrap();
	void			whoAmI();

private:
	std::string _name;
};

#endif//DIAMONDTRAP_HPP