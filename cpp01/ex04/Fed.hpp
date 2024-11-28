#ifndef FED_HPP
# define FED_HPP

#include <iostream>
#include <string>
#include <fstream>

typedef std::string str;

//file editor class

class Fed
{
public:
			Fed(str ifile, str ofile);
			~Fed();
	void	replace(str search, str rep);


private:
	str	_ifile;
	str	_ofile;
};

#endif