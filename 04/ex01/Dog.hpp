#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
private:
	Brain	*brainptr;
public:
	Dog();
	Dog(const Dog& copy);
	Dog&	operator=(const Dog& rhs);
	~Dog();
	
	std::string	getType(void);
};

#endif