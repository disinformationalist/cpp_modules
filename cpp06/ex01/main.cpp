#include "Serializer.hpp"

int main()
{
	Data	data;
	Data	*returned;

	data.amazing_thing = 42;
	data.ok_thing = "stuff for the thing";
	data.nothing = NULL;

	returned = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << std::endl;
	if (returned == &data)
		std::cout << "\033[32m""POINTERS MATCHED""\033[0m" << "\a" << std::endl << std::endl;
	else
		std::cout << "\033[31m""POINTERS NOT MATCHED""\033[0m" << std::endl << std::endl;


	std::cout << "And now the contents: " << std::endl << std::endl;

	std::cout << "Before: " << std::endl << std::endl;

	std::cout << "amazing thing: " << data.amazing_thing << std::endl;
	std::cout << "ok thing     : " << data.ok_thing << std::endl;
	std::cout << "nothing      : " << data.nothing << std::endl;

	std::cout << std::endl << "After: " << std::endl << std::endl;

	std::cout << "amazing thing: " << returned->amazing_thing << std::endl;
	std::cout << "ok thing     : " << returned->ok_thing << std::endl;
	std::cout << "nothing      : " << returned->nothing << std::endl;

	return 0;
}