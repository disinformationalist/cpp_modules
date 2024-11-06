#ifndef PHONEBOOK_HPP
# define PNONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits> //std::numeric limits

class Contact;

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	//methods
	bool		add_con();
	bool		search();
	void		display(const Contact& contact);
	std::string	truncate(const std::string& str) const;

private:
	Contact		contacts[8];
	int			index;

	void		addToBook(const Contact &contact);
};

#endif