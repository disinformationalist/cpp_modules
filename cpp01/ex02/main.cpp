#include <iostream>
#include <string>

int main( void )
{
	std::string brain;

	brain = "HI THIS IS BRAIN";

	std::string* brainPtr = &brain;
	std::string& brainRef = brain;

	std::cout << "String address: " << &brain << std::endl;
	std::cout << "Address held by pointer to string: " << brainPtr << std::endl;
	std::cout << "Address held by string ref: " << &brainRef << std::endl << std::endl;

	std::cout << "The value of the string: " << brain << std::endl;
	std::cout << "The value pointed to by the string pointer: " << *brainPtr << std::endl;
	std::cout << "The value pointed to by the string reference: " << brainRef << std::endl;

	return (0);
}