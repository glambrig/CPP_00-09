#include "RPN.hpp"

bool	isNum(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	isOperand(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (true);
	return (false);
}

int	main(int ac, char **av)
{
	rpn	rpn(ac, av[1]);

	try
	{
		int res = rpn.calculate();
		std::cout << res << std::endl;
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
}