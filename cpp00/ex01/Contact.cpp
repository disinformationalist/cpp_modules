#include "Contact.hpp"
#include <cctype>//isdigit
#include <iostream>


// Constructor / destructor

Contact::Contact()
{}

Contact::~Contact()
{}
 
//SETTTERS

bool	Contact::setFirstName(const std::string &firstname)
{
	if (!firstname.empty())
	{
		first_name = firstname;
		return (true);
	}
	else
	{
		std::cerr << "Error: first name cannot be empty." << std::endl;
		return (false);
	}
}

bool	Contact::setLastName(const std::string &lastname)
{
	if (!lastname.empty())
	{
		last_name = lastname;
		return (true);
	}
	else
	{
		std::cerr << "Error: last name cannot be empty." << std::endl;
		return (false);
	}
}

bool	Contact::setNickName(const std::string &nickname)
{
	if (!nickname.empty())
	{
		nick_name = nickname;
		return (true);
	}
	else
	{
		std::cerr << "Error: nick name cannot be empty." << std::endl;
		return (false);
	}
}

bool	Contact::setPhoneNumber(const std::string &phonenumber)
{	
	size_t i = -1;
	
	if (phonenumber.empty())
	{
		std::cerr << "Error: phone number cannot be empty." << std::endl;
		return (false);
	}
	while (++i < phonenumber.size())
	{
		if (!std::isdigit(phonenumber[i]))
		{
			std::cerr << "Error: phone number can only contain digits." << std::endl;
			return (false);
		}
	}
	phone_number = phonenumber;
	return (true);
}

bool	Contact::setDarkestSecret(const std::string &darkestsecret)
{
	if (!darkestsecret.empty())
	{
		darkest_secret = darkestsecret;
		return (true);
	}
	else
	{
		std::cerr << "Error: darkest secret cannot be empty." << std::endl;
		return (false);
	}
}

//GETTERS

std::string Contact::getFirstName() const
{
	return (first_name);
}

std::string Contact::getLastName() const
{
	return (last_name);
}

std::string Contact::getNickName() const
{
	return (nick_name);
}

std::string Contact::getPhoneNumber() const
{
	return (phone_number);
}

std::string Contact::getDarkestSecret() const
{
	return (darkest_secret);
}