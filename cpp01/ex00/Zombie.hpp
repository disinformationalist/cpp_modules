#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP	

#include <string>
#include <iostream>


class Zombie
{
public:
	Zombie( std::string name );
	~Zombie();

	void	announce( void ) const;

private:
	std::string name;
};


//can do put this in class with 'static' keyword in front
Zombie		*newZombie( std::string name );
void		randomChump( std::string name );

#endif