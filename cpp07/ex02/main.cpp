#include "Array.hpp"




int main()
{
	std::cout << "--------test with int type-------" << std::endl << std::endl;
	
	std::cout << "test construction with no param" << std::endl;
	
	Array<int> a;
	std::cout << "size: " << a.size() << std::endl;
	
	std::cout << "test construction with unsigned int n" << std::endl;
	
	Array<int> b(6);
	std::cout << "size: " << b.size() << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = static_cast<int>(i + 2);


	std::cout << "test copy construction" << std::endl;

	Array<int> c(b);
	std::cout << "size: " << b.size() << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;

	std::cout << "test copy assign" << std::endl;

	Array<int> d;

	d = b;

	
	
	std::cout << std::endl;
	
	/* Array<int> a(5);
	a[0] = 42;               // uses non-const version: returns int&
	
	const Array<int> b(5);
	int x = b[0];            // uses const version: returns const int&

	(void)x; */
	/* int* b = new int[4];
	for (int i = 0; i < 4; i++)
		std::cout << b[i] << std::endl;
	delete[] b; */
	
	/* Array<int> a(4);

	
	for (int i = 0; i < a.getSize(); i++)
		std::cout << a[i] << std::endl;
	 */
	






	return 0;

}