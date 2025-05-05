#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>

#define IMIN std::numeric_limits<int>::min()
#define IMAX std::numeric_limits<int>::max()
#define FMIN -3.402823e+38F
#define FMAX std::numeric_limits<float>::max()
#define DMIN -1.7976931348623157e+308
#define DMAX std::numeric_limits<double>::max()

typedef enum e_type
{
	CHAR,
	SPEC,
	INT,
	FLOAT,
	DOUBLE,
	NONE

} t_type;

class ScalarConverter
{
public:

static void convert(const std::string& in);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

};

void	printSpec(const std::string& in);
void	printChar(const std::string& in);
void	printInt(const std::string& in);
void	printFloat(const std::string& in);
void	printDouble(const std::string& in);
t_type	parseType(const std::string& in);


#endif
