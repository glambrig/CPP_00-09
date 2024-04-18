#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string	str;
	Harl		harl;

	if (ac != 2)
	{
		std::cout << "You really should work on your typing..."
			<< "you didn't even put the arguments in right :("
			<< std::endl;
		return (0);
	}
	str = av[1];
	harl.complain(str);
}