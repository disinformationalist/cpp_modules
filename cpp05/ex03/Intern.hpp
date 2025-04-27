#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"
# include <iostream>

class Intern
{
public:
   		Intern();
		Intern(const Intern& other);
    	Intern& operator=(const Intern& other);
   		~Intern();
		   
   AForm*	makeForm(const std::string& form, const std::string& target);		
};
		
//fts to make each
AForm* createShrub(const std::string& target);

AForm* createRobo(const std::string& target);

AForm* createPardon(const std::string& target);


#endif
