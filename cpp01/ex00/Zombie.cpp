#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name <<" destroyed" << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}