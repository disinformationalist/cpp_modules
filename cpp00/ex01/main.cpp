#include "PhoneBook.hpp"


int	main()
{
	PhoneBook	book;
	std::string	in;

	std::cout << "Phonebook ready" << std::endl;
	std::cout << "Available commands: EXIT, ADD, SEARCH" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Enter commmand: ";
		if (!std::getline(std::cin, in))
		{
			std::cout << "\nEnd of file signaled. Exiting." << std::endl;
			break ;
		}

		if (in.empty())
			continue ;

		if (in == "EXIT")
			break ;
		if (in == "ADD")
		{
			if (book.add_con())
				break ;
		}
		else if (in == "SEARCH")
		{
			if (book.search())
				break ;
		}
		else
		{
			std::cerr << "Invalid command" << std::endl 
					  << "Available commands: EXIT, ADD, SEARCH" 
					  << std::endl << std::endl;
		}
	}
	return (0);
}
