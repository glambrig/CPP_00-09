#ifndef WRONGANIMAL_CPP
#define WRONGANIMAL_CPP

#include <iostream>
#include <string>

class	WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal&	operator=(const WrongAnimal& rhs);
	~WrongAnimal();

	std::string	getType(void) const;
	void		makeSound(void) const;
};

#endif