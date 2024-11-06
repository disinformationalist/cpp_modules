#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();//constructor
	~Contact();//destructor

	//getters
	std::string	getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	//setters
	bool	setFirstName(const std::string &firstname);
	bool	setLastName(const std::string &lastname);
	bool	setNickName(const std::string &nickname);
	bool	setPhoneNumber(const std::string &number);
	bool	setDarkestSecret(const std::string &secret);

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
};

#endif

/* fields:
first name, last name, nickname, phone number, darkest secret. */