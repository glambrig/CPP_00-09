#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat				supercrat("mr. biceps", 1);
	Intern					kevin;

	AForm* shrub = kevin.makeForm("robotomy request", "AAAAA");
	// AForm* robo = kevin.makeForm("robo", "BBBBBB");	//Throws exception
	AForm* robo = kevin.makeForm("president", "CCCCC");
	AForm* pres = kevin.makeForm("shrubbery", "DDDDD");

	supercrat.signForm(*shrub);
	supercrat.signForm(*robo);
	supercrat.signForm(*pres);

	supercrat.executeForm(*shrub);
	supercrat.executeForm(*robo);
	supercrat.executeForm(*pres);

	delete shrub;
	delete robo;
	delete pres;

	return (0);
}