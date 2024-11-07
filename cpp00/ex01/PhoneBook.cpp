#include "PhoneBook.hpp"
#include <iomanip>//std::setw()

PhoneBook::PhoneBook() : index(0)
{}

PhoneBook::~PhoneBook()
{}

//adds contact to current index in book, updates the index

void PhoneBook::addToBook(const Contact &contact)
{
	contacts[index] = contact;
	index = (index + 1) % 8;
}

//creates contact reading in each value, then adds to book

bool	PhoneBook::add_con()
{
	Contact 	contact;
	std::string str;
	
	while (true)
	{
		std::cout << "Enter first name: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "\nEnd of file signaled. Exiting." << std::endl;
			return (true);
		}
		//std::getline(std::cin >> std::ws, str);
		if (contact.setFirstName(str))
			break ;
	}

	while (true)
	{
		std::cout << "Enter last name: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "\nEnd of file signaled. Exiting." << std::endl;
			return (true);
		}
		if (contact.setLastName(str))
			break ;
	}

	while (true)
	{
		std::cout << "Enter nickname: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "\nEnd of file signaled. Exiting." << std::endl;
			return (true);
		}
		if (contact.setNickName(str))
			break ;
	}

	while (true)
	{
		std::cout << "Enter phone number: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "\nEnd of file signaled. Exiting." << std::endl;
			return (true);
		}
		if (contact.setPhoneNumber(str))
			break ;
	}

	while (true)
	{
		std::cout << "Enter darkest secret: ";
		if (!std::getline(std::cin, str))
		{
			std::cout << "\nEnd of file signaled. Exiting." << std::endl;
			return (true);
		}
		if (contact.setDarkestSecret(str))
			break ;
	}

	addToBook(contact);
	std::cout << "Contact Added" << std::endl << std::endl;
	return (false);
}

std::string PhoneBook::truncate(const std::string& str) const
{
	if (str.length() > 9)
		return str.substr(0, 9) + ".";
	return (str);
}

//display contact

void	PhoneBook::display(const Contact& contact)
{
	std::cout << "|" << std::setw(10) << std::right << truncate(contact.getFirstName())
			  << "|" << std::setw(10) << std::right << truncate(contact.getLastName())
			  << "|" << std::setw(10) << std::right << truncate(contact.getNickName())
			  << std::endl;
}

//print all contacts, then print requested

bool	PhoneBook::search()
{
	int requested;

	if ((contacts[0].getFirstName()).empty())
	{
		std::cout << "Phonebook is empty, ADD contacts before using SEARCH." << std::endl << std::endl;
		return (false);
	}

	//print header
	std::cout << std::setw(10) << "Index"
			  << "|" << std::setw(10) << std::right << "First Name"
			  << "|" << std::setw(10) << std::right << "Last Name"
			  << "|" << std::setw(10) << std::right << "Nick Name"
			  << std::endl;
	std::cout << std::string(48, '-') << std::endl;


	//display all the contacts
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstName().empty())
			break ;
		std::cout << std::setw(10) << std::right << i;
		display(contacts[i]);
	}
	std::cout << std::endl;

	//request a number and print specified
	while (true)
	{
		std::cout << "Enter the index of the requested contact: ";
		std::cin >> requested;
		if (!std::cin)
		{
			if (std::cin.eof())
			{
				std::cout << "\nEnd of file signaled. Exiting." << std::endl;
				return (true);
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid entry" << std::endl;
			}
		}
		else if ((requested >= 0 && requested < 8))
		{
			//get contact at index
			if (contacts[requested].getFirstName().empty())
				std::cout << "Index " << requested << " not set" << std::endl;
			else
			{
				//display one field per line
				std::cout << std::endl;
				std::cout << "First Name: " << contacts[requested].getFirstName() << std::endl;
				std::cout << "Last Name: " << contacts[requested].getLastName() << std::endl;
				std::cout << "Nickname: " << contacts[requested].getNickName() << std::endl;
				std::cout << "Phone Number: " << contacts[requested].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << contacts[requested].getDarkestSecret() << std::endl;
				std::cout << std::endl;
				break ;
			}
		}
		else
		{
			std::cout << "Invalid index number" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << std::endl;
	}
	return (false);
}
