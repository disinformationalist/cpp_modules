#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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
	
	std::cout << std::endl << "------test concrete ortho------" << std::endl << std::endl;
	
	PresidentialPardonForm ppf("kif");

	std::cout << ppf << std::endl;

	PresidentialPardonForm ppf2(ppf);

	std::cout << "same as ppf " << ppf2 << std::endl;

	PresidentialPardonForm ppf3("zap");

	ppf3 = ppf2;

	std::cout << "same as ppf. " << ppf2 <<  "target: " << ppf3.getTarget() << std::endl;

	
	
	
	std::cout << std::endl << "------test Shrub------" << std::endl << std::endl;
	
	Bureaucrat* a = hire("zoidberg", 146);

	ShrubberyCreationForm f("anywhere");//sign: 145 exec: 137
	sign(f, *a);
	delete a;
	

	Bureaucrat* b = hire("farnsworth", 144);
	sign(f, *b);
	exec(f, *b);
	delete b;

	Bureaucrat* c = hire("leela", 137);
	
	exec(f, *c);
	delete c;

	std::cout << std::endl << "------test Robo------" << std::endl << std::endl;
	
	std::srand(std::time(0));
	
	RobotomyRequestForm r("bender");//sign: 72 exec: 45
	
	Bureaucrat* d = hire("amy", 73);

	sign(r, *d);
	delete d;

	Bureaucrat* e = hire("fry", 70);

	sign(r, *e);

	exec(r, *e);

	delete e;

	Bureaucrat* g = hire("hermes", 36);

	exec(r, *g);

	std::cout << std::endl << "------test pardon------" << std::endl << std::endl;
	
	PresidentialPardonForm p("Zapp Brannigan");// sign: 25 exec: 5
	
	sign(p, *g);
	
	delete g;

	Bureaucrat* h = hire("zoidberg", 24);

	sign(p, *h);

	exec(p, *h); 
	
	delete h;

	Bureaucrat* z = hire("Zaphod", 1);

	exec(p, *z); 
	
	
	delete z;
	
	return (0);
}