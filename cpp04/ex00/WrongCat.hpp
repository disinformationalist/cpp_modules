#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
				WrongCat();
				WrongCat( const WrongCat& other );
	WrongCat&	operator=( const WrongCat& other );
				~WrongCat();
	void		makeSound() const;

private:
};

#endif //WRONGCAT_HPP