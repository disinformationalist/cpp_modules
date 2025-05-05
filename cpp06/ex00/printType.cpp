#include "ScalarConverter.hpp"
#include <cerrno>
#include <cmath>
#include <iomanip>


void	printSpec(const std::string& in)
{
	if (in == "+inf" || in == "+inff")
	{
		std::cout << "char  : impossible"  << std::endl;
		std::cout << "int   : impossible"  << std::endl;
		std::cout << "float : +inff"  << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (in == "-inf" || in == "-inff")
	{
		std::cout << "char  : impossible"  << std::endl;
		std::cout << "int   : impossible"  << std::endl;
		std::cout << "float : -inff"  << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else //nan, nanf
	{
		std::cout << "char  : impossible"  << std::endl;
		std::cout << "int   : impossible"  << std::endl;
		std::cout << "float : nanf"  << std::endl;
		std::cout << "double: nan" << std::endl;
	} 
}

void	set_char(long in)
{
	if (in < 0 || in > 127)
		std::cout << "char  : impossible" << std::endl;
	else 
	{
		char c = static_cast<char>(in);
		if (!std::isprint(c))
			std::cout << "char  : Non displayable" << std::endl;
		else
			std::cout << "char  : " << c << std::endl;
	}
}
void	printChar(const std::string& in)
{
	char c = static_cast<char>(in[0]);
	if (!std::isprint(c))
		std::cout << "char  : Non displayable" << std::endl;
	else
		std::cout << "char  : " << c << std::endl;
	std::cout << "int   : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void setDouble(const std::string& in)
{
	char	*end;
	end = NULL;
	errno = 0;
	double val = std::strtod(in.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cout << "float : " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
	}
	else
	{
		if (val < DMIN || val > DMAX)
		{
			std::cout << "float : " << "impossible" << std::endl;
			std::cout << "double: " << "impossible" << std::endl;	
		}
		else 
		{
			if (val < FMIN || val > FMAX)
				std::cout << "float : " << "impossible" << std::endl;
			else
				std::cout << "float : " << static_cast<float>(val) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
		}
	}
}


void	printInt(const std::string& in)
{
	char	*end = NULL;	
	errno = 0;
	long	val = std::strtol(in.c_str(), &end, 10);
	if (errno == ERANGE || val < IMIN || val > IMAX)
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
	}
	else
	{
		if (val < 0 || val > 127)
			std::cout << "char  : impossible" << std::endl;
		else 
		{
			char c = static_cast<char>(val);
			if (!std::isprint(c))
				std::cout << "char  : Non displayable" << std::endl;
			else
				std::cout << "char  : " << c << std::endl;
		}
		std::cout << "int   : " << static_cast<int>(val) << std::endl;
	}
	setDouble(in);
}


void	printDouble(const std::string& in)
{
	char	*end;
	end = NULL;
	errno = 0;

	double val = std::strtod(in.c_str(), &end);

	//std::cout << std::setprecision(16) << "double: " << val << std::endl << std::endl; watch out for loss of precision in the cout->lim 6 digits

	if (errno == ERANGE || val < DMIN || val > DMAX)
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (val < FMIN || val > FMAX)
		{
			std::cout << "char  : impossible" << std::endl;
			std::cout << "int   : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << std::endl;
		}
		else if (val < IMIN || val > IMAX)
		{
			std::cout << "char  : impossible" << std::endl;
			std::cout << "int   : impossible" << std::endl;
			std::cout << "float : " << static_cast<float>(val) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << std::endl;
		}
		else
		{
			if (val < 0 || val > 127)
				std::cout << "char  : impossible" << std::endl;
			else 
			{
				char c = static_cast<char>(val);
				if (!std::isprint(c))
					std::cout << "char  : Non displayable" << std::endl;
				else
					std::cout << "char  : " << c << std::endl;
			}
			std::cout << "int   : " << static_cast<int>(val) << std::endl;
			if (fabs(val) - std::floor(fabs(val)) < .000005)
			{
				std::cout << "float : " << static_cast<float>(val) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
			}
			else
			{
				std::cout << "float : " << static_cast<float>(val) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(val) << std::endl;
			}
		}
	}
}

void	printFloat(const std::string& in)
{
	char	*end;
	end = NULL;
	errno = 0;

	double val = std::strtof(in.c_str(), &end);

	//std::cout << std::setprecision(16) << "double: " << val << std::endl << std::endl; watch out for loss of precision in the cout->lim 6 digits

	if (errno == ERANGE || val < DMIN || val > DMAX)
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (val < FMIN || val > FMAX)
		{
			std::cout << "char  : impossible" << std::endl;
			std::cout << "int   : impossible" << std::endl;
			std::cout << "float : impossible" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << std::endl;
		}
		else if (val < IMIN || val > IMAX)
		{
			std::cout << "char  : impossible" << std::endl;
			std::cout << "int   : impossible" << std::endl;
			std::cout << "float : " << static_cast<float>(val) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(val) << std::endl;
		}
		else
		{
			if (val < 0 || val > 127)
				std::cout << "char  : impossible" << std::endl;
			else 
			{
				char c = static_cast<char>(val);
				if (!std::isprint(c))
					std::cout << "char  : Non displayable" << std::endl;
				else
					std::cout << "char  : " << c << std::endl;
			}
			std::cout << "int   : " << static_cast<int>(val) << std::endl;
			if (fabs(val) - std::floor(fabs(val)) < .000005)
			{
				std::cout << "float : " << static_cast<float>(val) << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
			}
			else
			{
				std::cout << "float : " << static_cast<float>(val) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(val) << std::endl;
			}
		}
	}
}

