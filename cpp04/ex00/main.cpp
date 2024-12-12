#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();//base class only
	const Animal* meta2 = new Animal("wild animal");//base class only, with type param passed
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();


	std::cout << std::endl;

	std::cout << meta->getType() << std::endl;//base
	std::cout << meta2->getType() << std::endl;//base param passed
	std::cout << j->getType() << std::endl;//doggo
	std::cout << i->getType() << std::endl;//cat
	std::cout << k->getType() << std::endl;//wrongcat

	std::cout << std::endl;
	
	meta->makeSound();//unspecified
	meta2->makeSound();//wild animal
	j->makeSound();//dog
	i->makeSound(); //will output the cat sound!
	k->makeSound(); //will output the wrong cat sound!


	std::cout << std::endl;

	delete meta;
	delete meta2;
	delete i;
	delete j;
	delete k;

return (0);
}