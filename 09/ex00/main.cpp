#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	std::fstream	file;
	Bitcoin		btc;
	if (ac != 2)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return (1);
	}
	file.open(av[1], std::ios::in);
	if (!file)
	{
		std::cerr << "Error: error opening input file" << std::endl;
		return (1);
	}
	else
	{
		btc.putInMap(file);
		btc.printAll();
	}
	file.close();
	return (0);
}