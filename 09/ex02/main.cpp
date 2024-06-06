#include "PmergeMe.hpp"

bool	isNum(const std::string &s)
{
    std::string::const_iterator it = s.begin();

    while (it != s.end() && std::isdigit(*it))
		++it;
    return (!s.empty() && it == s.end());
}

int	main(int ac, char **av)
{
	(void)ac;
	try
	{
		PmergeMe	p(av);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
	return (0);
}