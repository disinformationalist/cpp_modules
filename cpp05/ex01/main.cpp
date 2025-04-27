#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl << "------test instantiate and print with overloaded <<------" << std::endl << std::endl;
	
	Form a("test", false, 22, 21);
	Form z(a);
	std::cout << z << std::endl;

	Form x("test2", true, 33, 33);

	x = a;
	std::cout << x << std::endl << std::endl;



	try
	{
		Form b("insurance", false, 11, 2); //continues until first exception caught then breaks, and throws
		std::cout << b << std::endl;

		Form c("insurance2", true, 22, 33);
		std::cout << c << std::endl;

		Form d("insurance3", true, 11, 0);
		Form e("insurance4", true, 12, 151);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	//using only one catch, loses separate handling ability
	std::cout << std::endl;
	std::string name = "reg";
	try
	{
		Form b(name, true, 151, 2);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception(reg): " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form b(name, true, 0, 73);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception(" << name << "): "<< e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form b(name, true, 33, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception(" << name << "): "<< e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form b(name, true, 55, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception(" << name << "): "<< e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat *bur = NULL;
	Form* c = NULL;
	name = "sign me";

	try
	{
		bur = new Bureaucrat("hermes", 36);
		c = new Form(name, false, 35, 33);
		c->beSigned(*bur);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << bur->getName() << " cannot sign " 
			  << c->getName() << "because " 
			  << Form::GradeTooLowException().what();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: "<< e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << *c << std::endl;

	try
	{
		bur->increment();
		c->beSigned(*bur);
		bur->decrement();
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << bur->getName() << " cannot sign " 
			  << c->getName() << "because " 
			  << Form::GradeTooLowException().what();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception(" << name << "): "<< e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << *c << std::endl; 


	delete c;
	delete bur;

	return (0);
}