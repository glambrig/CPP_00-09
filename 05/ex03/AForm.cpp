#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("default"), _execGrade(150), _signGrade(150), _signed(false)
{
	
}

AForm::AForm(std::string Name, int signGrade, int execGrade) : _name(Name),
	_execGrade(execGrade), _signGrade(signGrade), _signed(false)
{
	try
	{
		if (signGrade > 150 || execGrade > 150)
			throw ("AForm::GradeTooHighException");
		else if (signGrade < 1 || execGrade < 1)
			throw ("AForm::GradeTooLowException");
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
}

AForm::AForm(const AForm& copy) : _name(copy._name), _execGrade(copy.getExecGrade()), _signGrade(copy.getSignGrade())
{
	_signed = copy.getSigned();
}

AForm&	AForm::operator=(const AForm& rhs)
{
	this->_signed = rhs.getSigned();
	this->_signGrade = rhs.getSignGrade();
	return (*this);
}

AForm::~AForm()
{

}


std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	// return (this->_signed);
	if (this->_signed == true)
		return (true);
	return (false);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	try
	{
		if (signer.getGrade() > this->_signGrade)
		{
			this->_signed = false;
			throw ("AForm::GradeTooLowException");
		}
		else
			this->_signed = true;
	}
	catch (const char *exception)
	{
		std::cerr << signer.getName() << " : " << exception << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& stream, const AForm& rhs)
{
	stream << rhs.getName() << " " << rhs.getSigned()
		<< " " << rhs.getSignGrade() << " " << rhs.getExecGrade()
		<< std::endl;
	return (stream);
}

int	AForm::checkExecGrade(const Bureaucrat& b) const
{
	if (this->_signed == false)
		return (1);
	if (b.getGrade() > this->_execGrade)
		return (1);
	return (0);
}