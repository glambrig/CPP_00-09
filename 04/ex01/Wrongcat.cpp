#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string	WrongCat::getType(void)
{
	return (this->WrongAnimal::type);
}