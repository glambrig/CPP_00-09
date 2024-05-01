#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	if (this->getType().compare("WrongCat") == 0)
		std::cout << "the cat is barking like a dog! that's wrong!" << std::endl;
	else if (this->getType().compare("WrongDog") == 0)
		std::cout << "the dog is meowing like a cat! that's wrong!" << std::endl;
	else
		std::cout << "default Wronganimal noise??" << std::endl;
}
