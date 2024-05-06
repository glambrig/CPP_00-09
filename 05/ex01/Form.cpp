#include "Form.hpp"

Form::Form() : _name("default"), _execGrade(150), _signGrade(150), _signed(false)
{
	
}

Form::Form(std::string Name, int signGrade, int execGrade) : _name(Name),
	_execGrade(execGrade), _signGrade(signGrade), _signed(false)
{
	try
	{
		if (getSignGrade() > 150 || getExecGrade() > 150)
			throw ("Form::GradeTooHighException");
		else if (getSignGrade() < 1 || getExecGrade() < 1)
			throw ("Form::GradeTooLowException");
	}
	catch(std::string e)
	{
		std::cerr << e << std::endl;
	}
}

Form::Form(const Form& copy)
{
	if (this != &copy)
		*this = copy;
}

Form::operator=(const Form& rhs)
{
	if (this->_name.empty() == true)
		this->name = rhs;
	this->_signed = rhs.getSigned();
	this->_signGrade = rhs.;
	// this->_execGrade;
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

void	Form::beSigned(const BureauCrat& signer)
{
	try
	{
		if (signer.getGrade() > this->_signGrade)
			throw ("Form::GradeTooLowException");
		else
			this->_signed = true;
	}
	catch (const char *exception)
	{
		std::cerr << exception << std::endl;
	}
}

std::ostream& operator<<(std::ostream& stream, const Form& rhs) const
{
	stream << rhs.getName() << " " << rhs.getSigned()
		<< " " << rhs.getSignGrade() << " " << rhs.getExecGrade()
		<< std::endl;
	return (stream);
}