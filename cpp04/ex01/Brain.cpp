#include "Brain.hpp"

//construct and destruct

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "default idea";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy created" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment copied" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

//get and set

void	Brain::setIdea(std::string idea, int i)
{
	_ideas[i] = idea;
}

const std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
	{
		return ("index must be between 0 and 99 inclusively");
	}
	return (_ideas[i]);
}