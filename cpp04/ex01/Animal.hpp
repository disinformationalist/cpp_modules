#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

//base class Animal

class Animal
{
public:
				Animal( void );
				Animal( std::string type );
				Animal( const Animal& other );
		Animal&	operator=( const Animal& other );
		
		//virtual destructor to ensure the derived class destructor is also called
		virtual	~Animal();
		//virtual function allows derived class to override function, so the 
		//correct function is called for the class that calls it.
		virtual void	makeSound() const;
		std::string getType() const;

		//virtual for accesing brain in derived class, polymorphic case where say, 
		//an animal cat is made.
		// = 0 to make pure virtual if abstract class(defined in the derived class)
		//an abstract base class cannot make members of itself, must be used by derived.
		//this one will just return null for a plain animal

		virtual Brain* getBrain() const;
protected:
		std::string _type;
};

#endif //ANIMAL_HPP