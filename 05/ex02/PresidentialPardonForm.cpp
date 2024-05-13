#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "default_PresidentPardonForm";
}

PresidentialPardonForm::PresidentialPardonForm(std::string s) : AForm(s, 25, 5)
{
	this->_target = s;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	: AForm(copy)
{

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	AForm::operator=(rhs);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}
//End of canonical stuff

int	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try
	{
		if (this->getSigned() == false)
			throw ("PresidentialPardonForm::FormNotSigned");
		if (checkExecGrade(executor) == 1)
			throw ("PresidentialPardonForm::ExecutorGradeTooLow");
	}
	catch (const char *exception)
	{
		std::cerr << executor.getName() + " : " << exception << std::endl;
		return (1);
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (0);
}