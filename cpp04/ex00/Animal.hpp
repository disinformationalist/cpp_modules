#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
public:
				Animal( void );
				Animal( const Animal& other );
		Animal&	operator=( const Animal& other );
				~Animal();
	void		makeSound();
protected:
		std::string type;
};

#endif //ANIMAL_HPP