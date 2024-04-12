#include "Zombie.hpp"

std::string	Zombie::getName(void)
{
	return (name);
}

void	Zombie::announce(void)
{
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*Toggle is used so that newZombie() doesn't announce,
	but randomChump() does.*/
Zombie::Zombie(std::string name, bool toggle = true)
{
	this->name = name;
	if (toggle == true)
	{
		std::cout << name;
		Zombie::announce();
	}
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::getName() << " destroyed." << std::endl;
}
