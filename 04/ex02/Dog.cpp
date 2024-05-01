#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->Animal::type = "Dog";
	this->brainptr = new Brain;
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
	delete brainptr;
	std::cout << "Dog destructor called" << std::endl;
}

std::string	Dog::getType(void)
{
	return (this->Animal::type);
}

void	Dog::makeSound(void) const
{
	std::cout << "woof! woof wooof!!" << std::endl;
}