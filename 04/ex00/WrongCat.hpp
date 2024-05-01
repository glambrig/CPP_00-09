#ifndef WRONGCAT_CPP
#define WRONGCAT_CPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& copy);
	WrongCat&	operator=(const WrongCat& rhs);
	~WrongCat();

	std::string	getType(void);
};

#endif