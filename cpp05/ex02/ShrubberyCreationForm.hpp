#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
public:

							ShrubberyCreationForm();
							ShrubberyCreationForm(const std::string& target);
							ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	virtual 				~ShrubberyCreationForm();

	void					doIt() const;
	std::string&			getTarget();


private:
	std::string _target;

};

# endif // SHRUBBERYCREATIONFORM_HPP
