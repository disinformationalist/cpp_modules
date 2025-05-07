#include "Iter.hpp"

int main()
{
	std::cout << "testing int" << std::endl;
	
	int values[] = {1, 3, 4, 5, 7};

	iter(values, 5, add_two<int>);
	iter(values, 4, print_val<int>);

	

	std::cout << std::endl << "testing double" << std::endl;

	double values2[] = {1.5, 3.6, 7.8, 10.2};

	iter(values2, 4, add_two<double>);
	iter(values2, 4, print_val<double>);


	std::cout << std::endl << "testing const" << std::endl;
	
	const int values3[] = {1, 3, 4, 5, 7};

	iter(values3, 5, print_val<int>);

	std::cout << std::endl << "testing char" << std::endl;
	
	char values4[] = {'a', 'b', 'c', 'd'};

	iter(values4, 4, add_two<char>);
	iter(values4, 4, print_val<char>);

	std::cout << std::endl << "testing empty" << std::endl;

	int empty[] = {};
	iter(empty, 0, print_val<int>);



	return 0;

}