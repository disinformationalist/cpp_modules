#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "Usage: ./converter <value>" << std::endl;

	return (0);
}
/* 
For testing non printalble chars..

./converter $'\x1B'  ESC
$'\x7F'  DEL
$'\x00'  NUL
$'\x07'  BELL */