#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl << "------test instantiate and print with overloaded <<------" << std::endl << std::endl;
	
	//cons
	
	Bureaucrat f("fry", 111);

	Bureaucrat g("bender", 33);

	Bureaucrat h(f);
	
	g = f;

	std::cout << g << std::endl;
	
	std::cout << h << std::endl;
	
	//------
	
	Bureaucrat a("hermes", 36);
	
	std::cout << a << std::endl << std::endl;
	
	
	
	std::cout << "------test too high/low instantiation-------" << std::endl << std::endl;
	
	
	
	//using separate catchs for too high/low
	try
	{
		Bureaucrat b("fry", 0);//too high
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	Bureaucrat* c = NULL;


	//using only one catch, loses separate handling ability
	try
	{
		c = new Bureaucrat("zoidberg", 151);//too low	
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete c;
	
	
	std::cout << "------test increment and decrement------" << std::endl << std::endl;
	try
	{
		Bureaucrat d("leela", 1);//msgs "too high" and "destroyed" should be out of order, leaving scope before catch..
		d.increment();//should throw and exit try block here
		d.decrement();
		std::cout << d << std::endl << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl << std::endl;
	}
	

	try
	{
		Bureaucrat e("farnsworth", 150);
		e.decrement();
		e.increment();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	


	return (0);
}