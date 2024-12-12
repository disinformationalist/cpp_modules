#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	/* //can no longer instantiate just animal as it is now abstract
	const Animal* test = new Animal();
	delete test; */

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;


	Animal *pets[6] = {new Dog(), new Cat(), new Dog(), new Cat(),
	new Dog(), new Cat()};

	//set the idea at index 2 to dreaming for pets[2] (dog)
	pets[2]->getBrain()->setIdea("dreaming...", 2);
	//set index 4 
	pets[4]->getBrain()->setIdea("running...", 4);
	std::cout << std::endl;
	
	//before copy..
	std::cout << "pets[2] thinks: " << pets[2]->getBrain()->getIdea(2) << std::endl;
	std::cout << "pets[4] thinks: " << pets[4]->getBrain()->getIdea(2) << std::endl;

	//dynamic_cast to from animal to use dog operator=
	Dog* to = dynamic_cast<Dog*>(pets[4]);
	Dog* from = dynamic_cast<Dog*>(pets[2]);
	*to = *from;

	//check idea..
	std::cout << "pets[2] thinks: " << pets[2]->getBrain()->getIdea(2) << std::endl;
	std::cout << "pets[4] thinks: " << pets[4]->getBrain()->getIdea(2) << std::endl << std::endl;

	//check copy constructor
	pets[1]->getBrain()->setIdea("mice...", 3);
	pets[3]->getBrain()->setIdea("birds...", 3);

	std::cout << "pets[1] thinks: " << pets[1]->getBrain()->getIdea(3) << std::endl;
	std::cout << "pets[3] thinks: " << pets[3]->getBrain()->getIdea(3) << std::endl;


	Cat* orig = dynamic_cast<Cat*>(pets[1]);
	Cat catcopy(*orig);

	std::cout << "pets[1] thinks: " << orig->getBrain()->getIdea(3) << std::endl;
	std::cout << "pets[3] thinks: " << catcopy.getBrain()->getIdea(3) << std::endl;


//these still work though not explicitly defined in animal(now abstract)
	std::cout << std::endl;
	pets[0]->makeSound();
	pets[1]->makeSound();
	std::cout << std::endl;


	for (int i = 0; i < 6; i++)
		delete pets[i];



return (0);
}