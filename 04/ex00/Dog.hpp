#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
// private:
	// std::string	_type;
public:
	Dog();
	Dog(const Dog& copy);
	Dog&	operator=(const Dog& rhs);
	~Dog();
	
	std::string	getType(void);
};

#endif