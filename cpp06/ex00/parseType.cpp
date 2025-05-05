#include "ScalarConverter.hpp"

static inline bool isSpec(const std::string& in)
{
	if (in == "+inf" || in == "-inf" || in == "nan" \
	|| in == "+inff" || in == "-inff" || in == "nanf")
	return (true);
	return false;
}

static inline bool	isInt(const std::string& in)
{
	size_t	i = 0;
	
	if (in[i] == '+' || in[i] == '-')
		i++;
	while (i < in.length())
	{
		if (!isdigit(in[i]))
			return false;
		i++;
	}
	return (true);
}

static inline bool	isFloat(const std::string& in)
{
	size_t	i = 0;
	bool	dot = false;

	if (in[i] == '+' || in[i] == '-')
		i++;
	while (i < in.length() - 1)
	{
		if (in[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(in[i]))
			return false;
		i++;
	}
	if (in[i] != 'f')
		return false;
	return dot;
}

static inline bool isDouble(const std::string& in)
{
	size_t	i = 0;
	bool	dot = false;

	if (in[i] == '+' || in[i] == '-')
		i++;
	while (i < in.length())
	{
		if (in[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(in[i]))
			return false;
		i++;
	}
	return dot;
}

t_type	parseType(const std::string& in)
{
	if (in.length() == 1 && !std::isdigit(in[0]))
		return (CHAR);
	else if (isSpec(in))
		return (SPEC);
	else if (isInt(in))
		return (INT);
	else if (isFloat(in))
		return (FLOAT);
	else if (isDouble(in))
		return (DOUBLE);
	else
		return (NONE);
}