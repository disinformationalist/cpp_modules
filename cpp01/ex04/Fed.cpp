#include "Fed.hpp"

Fed::Fed(str ifile, str ofile) : _ifile(ifile), _ofile(ofile)
{
}

Fed::~Fed()
{
}

void	Fed::replace(str search, str rep)
{
	str		line;
	size_t	spot;

	if (search.empty())
	{
		std::cerr << "Error: string to be replaced cannot be empty." << std::endl;
		return ;
	}

	std::ifstream in_File(_ifile.c_str());
	if (!in_File.is_open())
	{
		std::cerr << "Error: input file could not be opened." << std::endl;
		return ;
	}
	
	if (in_File.peek() == EOF)
	{
		std::cerr << "Error: the input file is empty." << std::endl;
		in_File.close();
		return ;
	}

	std::ofstream out_File(_ofile.c_str());
	if (!out_File.is_open())
	{
		std::cerr << "Error: output file could not be made." << std::endl;
		in_File.close();
		return ;
	}

	while (std::getline(in_File, line))
	{
		spot = line.find(search);
		while (spot != str::npos)
		{
			//remove old
			line.erase(spot, search.length());

			//set new
			line.insert(spot, rep);

			//move to next
			spot = line.find(search, spot + rep.length());
		}
		out_File << line << std::endl;
	}
	std::cout << "Replacement complete." << std::endl;
	in_File.close();
	out_File.close();
}