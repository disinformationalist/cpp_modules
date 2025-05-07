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
	
	
	

	//char
	
	

	/* //int
	
	int i = static_cast<int>(val);

	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "Int: Not representable within limits of type 'int'." << std::endl;
	else
		std::cout << "Int: " << i << std::endl;

	//float

	float f = static_cast<float>(val);

	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
		std::cout << "Float: Not representable within limits of type 'float'." << std::endl;
	else
		std::cout << "Float: " << f << std::endl;


	//double

	if (val < std::numeric_limits<double>::min() || val > std::numeric_limits<double>::max())
		std::cout << "Double: Not representable within limits of type 'double'." << std::endl;
	else
		std::cout << "Double: " << val << std::endl; */
}
