#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printNumList();

	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}

	std::cout << "\n----------------------------\n" << std::endl;

	Span bigspan(120);
	for (int i = 0; i < 10; i++)
	{
		bigspan.addNumber(i);
	}
	bigspan.printNumList();
	std::cout << std::endl;

	try
	{
		std::vector<int> test(100, 42);
		bigspan.addMany(test);
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
	}
	bigspan.printNumList();
	return 0;
}