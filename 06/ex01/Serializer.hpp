#pragma once

#include <stdint.h>
#include <iostream>
#include <cstddef>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();
public:
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& rhs);
	~Serializer();

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};