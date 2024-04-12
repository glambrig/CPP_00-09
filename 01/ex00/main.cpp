#include "Zombie.hpp"

int	main(void)
{
	Zombie *a = newZombie("fart");
	Zombie *b = newZombie("AAAAA");
	Zombie *c = newZombie("qwerty");

	randomChump("asdf");
	std::cout << std::endl;
	std::cout << a->getName();
	a->announce();
	std::cout << b->getName();
	b->announce();
	std::cout << c->getName();
	c->announce();
	delete a;
	delete b;
	delete c;
	return (0);
}
