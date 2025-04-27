#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:

							RobotomyRequestForm();
							RobotomyRequestForm(const std::string& target);
							RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	virtual					~RobotomyRequestForm();

	void					doIt() const;
	std::string&			getTarget();

private:
	std::string _target;

};

#endif // ROBOTOMYREQUESTFORM_HPP