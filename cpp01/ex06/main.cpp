#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl 
				  << "Available levels: DEBUG, INFO, WARNING, ERROR, OFF" 
				  << std::endl;
		return (1);
	}
	Harl harl;
	
	harl.filter(av[1]);
	return (0);
}