#include "Fed.hpp"

int main(int ac, char **av)
{
	str in_File;
	str search;
	str out_File;
	str rep;
	
	if (ac != 4)
	{
		std::cerr << "Usage: ./fed <in_File> <string to replace> <replace with>" << std::endl;
		return (1);
	}
	in_File = av[1];
	search = av[2];
	rep = av[3];
	
	if (rep == search)
	{
		std::cerr << "Error: string to replace and string to replace with must be different." << std::endl;
		return (1);
	}

	out_File = in_File + ".replace";

	//fed instance with initializer list
	Fed edit(in_File, out_File);

	//pass params into replace function
	edit.replace(search, rep);

	return (0);
}
/* 
Create a program that takes three parameters in the following order: a in_File and
two strings, s1 and s2.
It will open the file <in_File> and copies its content into a new file
<in_File>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your */