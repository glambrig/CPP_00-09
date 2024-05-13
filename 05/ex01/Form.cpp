#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _execGrade(150), _signGrade(150), _signed(false)
{
	
}

Form::Form(std::string Name, int signGrade, int execGrade) : _name(Name),
	_execGrade(execGrade), _signGrade(signGrade), _signed(false)
{
	try
	{
		if (signGrade > 150 || execGrade > 150)
			throw ("Form::GradeTooHighException");
		else if (signGrade < 1 || execGrade < 1)
			throw ("Form::GradeTooLowException");
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
}

Form::Form(const Form& copy) : _name(copy.getName()), _execGrade(copy.getExecGrade())
{
	if (this != &copy)
		*this = copy;
}

Form&	Form::operator=(const Form& rhs)
{
	// if (this->_name.empty() == true)
	// 	this->_name = rhs.getName();
	this->_signed = rhs.getSigned();
	this->_signGrade = rhs.getSignGrade();
	return (*this);
}

Form::~Form()
{

}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	// return (this->_signed);
	if (this->_signed == true)
		return (true);
	return (false);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

void	Form::beSigned(const Bureaucrat& signer)
{
	try
	{
		if (signer.getGrade() > this->_signGrade)
		{
			this->_signed = false;
			throw ("Form::GradeTooLowException");
		}
		else
			this->_signed = true;
	}
	catch (const char *exception)
	{
		std::cerr << signer.getName() << " : " << exception << std::endl;
	}
	signer.signForm(*this);
}

// std::ostream& Form::operator<<(const std::ostream stream)
// {
// 	stream << this->getName() << " " << this->getSigned()
// 		<< " " << this->getSignGrade() << " " << this->getExecGrade()
// 		<< std::endl;
// 	return (stream);
// }

std::ostream&	operator<<(std::ostream& stream, const Form& rhs)
{
	stream << rhs.getName() << " " << rhs.getSigned()
		<< " " << rhs.getSignGrade() << " " << rhs.getExecGrade()
		<< std::endl;
	return (stream);
}