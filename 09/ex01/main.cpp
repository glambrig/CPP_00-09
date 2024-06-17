#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN rpn;
	
	if (ac != 2)
	{
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return (1);
	}

	try
	{
		rpn.solveExpression(av[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
