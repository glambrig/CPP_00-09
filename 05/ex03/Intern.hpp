#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Intern
{
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& rhs);
	~Intern();

	AForm	*makeForm(std::string formName, std::string formTarget);
};

std::ostream& operator<<(std::ostream& stream, const Intern& rhs);

#endif