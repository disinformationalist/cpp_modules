#include "Zombie.hpp"

int main()
{
	Zombie*	zom2;

	std::cout << "creating stack zombie..." << std::endl;
	randomChump("Lucien Greaves");
	std::cout << std::endl;

	std::cout << "creating heap zombie..." << std::endl;
	zom2 = newZombie("Todd");
	zom2->announce();

	delete zom2;
	return (0);
}