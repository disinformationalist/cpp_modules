#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
	std::cout << "Intern assignment operator called" << std::endl;
    return (*this);
}

//form creators

AForm* createShrub(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* createRobo(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}


AForm*	Intern::makeForm(const std::string& form, const std::string& target)
{
	std::string Forms[3];
	int i;

	Forms[0] = "shrubbery creation";
	Forms[1] = "robotomy request";
	Forms[2] = "presidential pardon";

	AForm* (*Creators[3])(const std::string&);

	Creators[0] = &createShrub;
	Creators[1] = &createRobo; 
	Creators[2] = &createPardon;
	
	i = -1; 
	while (++i < 3)
	{
		if (form == Forms[i])
		{
			std::cout <<"Intern creates " << form << std::endl;
			return (Creators[i](target));
	
		}
	}
	std::cout << form << " form does not exist." << std::endl;
	
	return (NULL);
}
