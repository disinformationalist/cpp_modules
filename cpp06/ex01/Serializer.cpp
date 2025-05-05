#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = other;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    std::cout << "Serializer assignment operator called" << std::endl;
	if (this != &other)
		*this = other;
    return *this;
}

//serialize and back

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}