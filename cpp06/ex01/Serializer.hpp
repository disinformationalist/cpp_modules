#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
public:

static uintptr_t	serialize(Data* ptr);
static Data* 		deserialize(uintptr_t raw);

private:
					Serializer();
					Serializer(const Serializer& other);
					~Serializer();
		Serializer& operator=(const Serializer& other);
};

#endif
