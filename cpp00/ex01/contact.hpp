#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

typedef std::string str;
# define cout std::cout
# define endl std::endl

class Contact
{
public:
	Contact();//default empty constructor
	~Contact();//destructor

	//getters
	str	getFirstName() const;
	str	getLastName() const;
	str	getNickName() const;
	str	getPhoneNumber() const;
	str	getDarkestSecret() const;

	//setters
	void	setFirstName(const str &firstname);
	void	setLastName(const str &lastname);
	void	setNickName(const str &nickname);
	void	setPhoneNumber(const str &number);
	void	setDarkestSecret(const str &secret);

private:
	str first_name;
	str last_name;
	str nickname;
	str phone_number;
	str darkest_secret;
};

#endif

/* fields:
first name, last name, nickname, phone number, darkest secret. */