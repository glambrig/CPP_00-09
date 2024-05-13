#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat				bob("bob", 5);
	Bureaucrat				gary("gary", 26);
	Bureaucrat				idiot("idiot", 145);
	PresidentialPardonForm	pres("AAAAAAAA");
	RobotomyRequestForm		robo("BBBBBBB");
	ShrubberyCreationForm	shrub("CCCCCC");

	std::cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << std::endl;
	std::cout << gary.getName() << ", bureaucrat grade " << gary.getGrade() << std::endl;
	std::cout << idiot.getName() << ", bureaucrat grade " << idiot.getGrade() << std::endl;

	std::cout << std::endl;

///////////////////////AAAAAAAA
	bob.signForm(pres);
	gary.signForm(pres);	//WILL NOT PRINT A MESSAGE
	idiot.signForm(pres);	//WILL NOT PRINT A MESSAGE
	std::cout << std::endl;

	bob.executeForm(pres);
	gary.executeForm(pres);
	idiot.executeForm(pres);
	std::cout << std::endl;
///////////////////////////////BBBBBB
	idiot.signForm(robo);
	gary.signForm(robo);
	bob.signForm(robo);
	std::cout << std::endl;

	bob.executeForm(robo);
	gary.executeForm(robo);
	idiot.executeForm(robo);
	std::cout << std::endl;

///////////////////////////////CCCCCCCCC
	gary.signForm(shrub);
	bob.signForm(shrub);
	idiot.signForm(shrub);
	std::cout << std::endl;

	bob.executeForm(shrub);
	std::cout << std::endl;

	std::cout << pres;
	std::cout << robo;
	std::cout << shrub;
	return (0);
}