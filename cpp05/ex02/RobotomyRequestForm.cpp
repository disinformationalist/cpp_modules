#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", false, 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
: AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::doIt() const
{
	
	double robo;

	robo = static_cast<double>(std::rand()) / (RAND_MAX);
	std::cout << "Brrrrrrrrrrrr....." << std::endl
			  << "DDDddddRRRRdrrrrrrrrrr......." << std::endl
			  << " Tick.. Tick.. Clank." << std::endl << std::endl;

	std::cout << "robo: " << robo << std::endl;
	if (robo < .5)
		std::cout << "Robotomy of " << _target << " was successful!" << std::endl;
	else
		std::cout << "Robotomy of " << _target << " has Failed:(" << std::endl;
}

std::string&	RobotomyRequestForm::getTarget()
{
	return (_target);
}