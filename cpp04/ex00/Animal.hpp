#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

//base class Animal

class Animal
{
public:
				Animal( void );
				Animal( std::string type );
				Animal( const Animal& other );
		Animal&	operator=( const Animal& other );
		
		//virtual destructor to ensure the derived class destructor is called
		virtual	~Animal();
		//virtual function allows derived class to override function, so the 
		//correct function is called for the class that calls it.
virtual void	makeSound() const;
	std::string getType() const;
protected:
		std::string _type;
};

#endif //ANIMAL_HPP