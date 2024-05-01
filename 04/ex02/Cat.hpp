#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
private:
	Brain	*brainptr;
public:
	Cat();
	Cat(const Cat& copy);
	Cat&	operator=(const Cat& rhs);
	~Cat();

	std::string	getType(void);
	void		makeSound(void) const;
};

#endif