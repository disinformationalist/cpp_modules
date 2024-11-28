#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

typedef std::string str;

class Weapon
{
public:
					Weapon( str type );
					~Weapon();
	const str&		getType( void );
	void			setType( str type );
	

private:
	str _type;
};

#endif

/* Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as param-
eter.*/
