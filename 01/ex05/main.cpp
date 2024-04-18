#include "Harl.hpp"

int	main(void)
{
	std::string	str;
	Harl		harl;

	while (1)
	{
		std::cout << "How would you like to complain?"
			<< " (debug, info, warning, error)" << std::endl;
		std::cin >> str;
		harl.complain(str);
	}
}