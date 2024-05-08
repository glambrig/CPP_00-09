#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	bob("bob", 130);
	Bureaucrat	gary("gary", 150);
	Form		f1("unimportant paper", 140, 50);
	Form		f2("SUPER IMPORTANT DOCUMENT", 50, 1);
	// Form		error("sample document", 999, 30);

	std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() <<std::endl;
	std::cout << gary.getName() << ", bureaucrat grade " << gary.getGrade() <<std::endl;
	f1.beSigned(bob);
	f1.beSigned(gary);
	f2.beSigned(bob);
	f2.beSigned(gary);
	std::cout << f1;
	std::cout << f2;
	return (0);
}