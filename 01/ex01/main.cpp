#include "Zombie.hpp"

int	main(void)
{
	Zombie *a = zombieHorde(5, "terry");

	delete[] a;
}
