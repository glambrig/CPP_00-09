#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string s) : AForm(s, 72, 45)
{
	_target = s;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm& rhs)
{
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

int	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	static unsigned int i = 0;

	try
	{
		if (this->getSigned() == false)
			throw ("RobotomyRequestForm::FormNotSigned");
		if (checkExecGrade(executor) == 1)
			throw ("RobotomyRequestForm::ExecutorGradeTooLow");
	}
	catch (const char *exception)
	{
		std::cerr << executor.getName() + " : " << exception << std::endl;
		return (1);
	}
	std::cout << "DDRRRRR ZZZZZZZZZZ BRBRBRBRBRBRBBRBRRRR" << std::endl;
	if (i++ % 2 == 0)
		std::cout << _target + " has been successfully robotomized :)" << std::endl;
	else
		std::cout << "robotomization failed for " + _target << std::endl;
	return (0);
}