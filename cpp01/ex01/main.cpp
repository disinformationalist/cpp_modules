#include "Zombie.hpp"

int main (void)
{
	Zombie* horde;
	int		i;
	int		N;

	std::cout << "Enter a horde size: ";
	std::cin >> N;
	std::cout << std::endl;

	horde = zombieHorde(N, "Todd");

	for (i = 0; i < N; i++)
		horde[i].announce();
	std::cout << std::endl;
	
	delete[] horde;
	return (0);
}