#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	this->type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	if (this->getType().compare("Cat") == 0)
		std::cout << "meow meoww" << std::endl;
	else if (this->getType().compare("Dog") == 0)
		std::cout << "woof! woof!!" << std::endl;
	else
		std::cout << "(default animal noise??)" << std::endl;
}
