#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat a("bureaucrat bob", 50);

	std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() <<std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "incrementing " << a.getName() << "'s grade!" << std::endl;
		a.incrGrade();
	}
	std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() <<std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << "decrementing " << a.getName() << "'s grade!" << std::endl;
		a.decrGrade();
	}
	std::cout << a.getName() << ", bureaucrat grade " << a.getGrade() <<std::endl;
	std::cout << a << a << a;

	try
	{
		Bureaucrat b("bureaucrat bill", 999);	//Throws exception
	}
	catch (...)
	{
		std::cout << "SOME TEXT THAT WILL BE SKIPPED..." << std::endl;
		std::cout << "SOME TEXT THAT WILL BE SKIPPED..." << std::endl;
		std::cout << "SOME TEXT THAT WILL BE SKIPPED..." << std::endl;
		std::cout << "SOME TEXT THAT WILL BE SKIPPED..." << std::endl;
	}
	return (0);
}