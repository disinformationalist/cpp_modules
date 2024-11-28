#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

typedef std::string str;

class Zombie
{
public:
			Zombie();
			~Zombie();
	void	announce( void ) const;
	void	setName( str name);
	
private:
	str _name;
};

Zombie*		zombieHorde( int N, str name );

#endif