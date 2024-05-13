#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : _name(Name)
{
	try
	{
		if (Grade > 150)
			throw ("Bureaucrat::GradetooHighException");
		else if (Grade < 1)
			throw ("Bureaucrat::GradetooLowException");
	}
	catch(const char *exception)
	{
		std::cerr << exception << std::endl;
	}
	this->_grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	// *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void Bureaucrat::incrGrade(void)
{
	try
	{
		if (this->_grade > 150)
			throw ("Bureaucrat::GradetooHighException");
		else if (this->_grade < 1)
			throw ("Bureaucrat::GradetooLowException");
	}
	catch (const char *exception)
	{
		std::cerr << exception << std::endl;
	}
	(this->_grade)--;
}

void Bureaucrat::decrGrade(void)
{
	try
	{
		if (this->_grade > 150)
			throw ("Bureaucrat::GradetooHighException");
		else if (this->_grade < 1)
			throw ("Bureaucrat::GradetooLowException");
	}
	catch (const char *exception)
	{
		std::cerr << exception << std::endl;
	}
	(this->_grade)++;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
	stream << rhs.getName() << " " << rhs.getGrade() << std::endl;
	return (stream);
}

void	Bureaucrat::signForm(AForm& form)
{
	if (this->_grade <= form.getSignGrade() && form.getSigned() == false)
	{
		std::cout << this->getName() << " signed " << form.getName()
			<< std::endl;
	}
	else if (form.getSigned() == true)
		return ;
	else
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because bureaucrat's grade wasn't high enough" << std::endl;
	}
	form.beSigned(*this);
}

void		Bureaucrat::executeForm(const AForm& form)
{
	form.execute(*this);
	// try
	// {
	// 	if (form.execute(*this) == 1)
	// 		throw ("executeForm : UnsuccessfulExecution");
	// }
	// catch (const char *e)
	// {
	// 	std::cout << e << std::endl;
	// }
}