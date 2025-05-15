#include "ScalarConverter.hpp"

//ortho, not really used here

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	std::cout << "ScalarConverter assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

//converter

void	ScalarConverter::convert(const std::string& in)
{
	t_type type = parseType(in);

	switch (type)
	{
		case 0:
			printChar(in);
			break ;
		case 1:
			printSpec(in);
			break ;
		case 2:
			printInt(in);
			break ;
		case 3:
			printFloat(in);
			break ;
		case 4:
			printDouble(in);
			break ;
		case 5:
			std::cout << "Invalid entry" << std::endl;
			break ;
	}
}
