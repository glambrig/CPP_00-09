#include "Intern.hpp"

std::string	strToUpper(std::string s)
{
	std::string	res;

	res = s;
	for (size_t i = 0; i < res.length(); i++)
		res[i] = std::toupper(s[i]);
	return (res);
}

Intern::Intern()
{

}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{

}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	s = strToUpper(formName);

	try
	{
		if (s.compare(0, 8, "ROBOTOMY") == 0)
		{
			RobotomyRequestForm *robo = new RobotomyRequestForm(formTarget);
			return (robo);
		}
		if (s.compare(0, 5, "SHRUB") == 0)
		{
			ShrubberyCreationForm *shrub = new ShrubberyCreationForm(formTarget);
			return (shrub);
		}
		if (s.compare(0, 9, "PRESIDENT") == 0)
		{
			PresidentialPardonForm *pres = new PresidentialPardonForm(formTarget);
			return (pres);
		}
		throw ("Intern : NoFormMatchException");
	}
	catch (const char *e)
	{
		std::cerr << e << std::endl;
	}
	return (NULL);
}