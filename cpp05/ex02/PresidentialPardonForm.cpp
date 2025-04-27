#include "PresidentialPardonForm.hpp"

//ortho

PresidentialPardonForm::PresidentialPardonForm() 
: AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm::AForm(other), _target(other._target)  
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::doIt() const
{
	std::cout << "A presidential pardon by Zaphod Beeblebrox has hereby been issued to " 
			  << _target << "." << std::endl;	
}

std::string&	PresidentialPardonForm::getTarget()
{
	return (_target);
}