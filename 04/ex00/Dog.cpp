#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->Animal::type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	this->type = rhs.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

std::string	Dog::getType(void)
{
	return (this->Animal::type);
}