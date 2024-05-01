#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->Animal::type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	this->type = rhs.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string	Cat::getType(void)
{
	return (this->Animal::type);
}