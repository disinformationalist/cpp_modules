#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal
{
public:
			Dog();
			Dog( const Dog& other);
	Dog&	operator=( const Dog& other );
			~Dog();		
	void	makeSound() const;
	Brain*	getBrain() const;

private:
	Brain *_brain;
};

#endif //DOG_HPP