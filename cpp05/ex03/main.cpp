#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void	exec(AForm& f, Bureaucrat& b)
{
	try
	{
		f.execute(b);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << b.getName() << " cannot execute " 
			  << f.getName() << " because " 
			  << e.what() << std::endl;
	}
}


void	sign(AForm& f, Bureaucrat& b)
{
	try
	{
		f.beSigned(b);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << b.getName() << " cannot sign " 
			  << f.getName() << " because " 
			  << e.what() << std::endl;
	}
}

Bureaucrat*	hire(const std::string name, int grade)
{
	Bureaucrat* b = NULL;
	try
	{
		b = new Bureaucrat(name, grade);
	}
	catch(const std::exception& e)
	{
		std::cout << "cannot hire " << name << " because " << e.what() << std::endl;
	}
	return (b);
}

int main()
{
	std::cout << std::endl << "------test Intern------" << std::endl << std::endl;
	
	Intern a;

	Intern b(a);
	
	Intern c;
	
	c = a;

	
	
	Intern namelessIntern;
	AForm* rrf = NULL;

	rrf = namelessIntern.makeForm("robotomy request", "Bender");

	delete rrf;
	
	std::cout << std::endl;

	rrf = namelessIntern.makeForm("shrubbery creation", "mars");

	delete rrf;
	std::cout << std::endl;

	rrf = namelessIntern.makeForm("presidential pardon", "zap");

	delete rrf;
	std::cout << std::endl;


	rrf = NULL;
	
	rrf = namelessIntern.makeForm("Waffle request", "zap");
	
	if (rrf)
		delete rrf;

	return (0);
}