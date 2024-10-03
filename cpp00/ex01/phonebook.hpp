#ifndef PHONEBOOK_HPP
# define PNONEBOOK_HPP

#include <contact.hpp>
#include <iostream>
#include <string>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	// add methods(function prototypes for add, etc... here)
private:
	Contact contacts[8];
};



#endif