#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base*	generate(void)
{
	int rando = std::rand() % 3;
	
	switch(rando)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return (NULL);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "None" << std::endl;
}
void	identify(Base& p)
{
	try
	{
		A& instance = dynamic_cast<A&>(p);
		(void)instance;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		B& instance = dynamic_cast<B&>(p);
		(void)instance;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		C& instance = dynamic_cast<C&>(p);
		(void)instance;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	
}

int main()
{
	std::srand(std::time(0));

	Base* instance = generate();

	identify(instance);

	std::cout << std::endl;

	Base& ref = *instance;

	identify(ref);

	delete instance;

	return 0;
}