#include <iostream>

namespace nothing
{
	void	print(void)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}

namespace args
{
	void	print(char **av)
	{
		int i = 1, k;

		while (av[i])
		{
			if (i > 1 && av[i][0] != ' ' && av[i - 1][k - 1] != ' ')
				std::cout << ' ';
			k = 0;
			while (av[i][k])
			{
				if (av[i][k] >= 'a' && av[i][k] <= 'z')
					std::cout << (char)(av[i][k] - 32);
				else
					std::cout << av[i][k];
				k++;
			}
			i++;
		}
		std::cout << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		nothing::print();
	else
		args::print(av);
	return (0);
}

