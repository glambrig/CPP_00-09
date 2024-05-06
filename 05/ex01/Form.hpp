#ifndef	FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class	Form
{
private:
	std::string const	_name;
	bool				_signed;
	int					_signGrade;
	int const			_execGrade;
public:
	Form();
	Form(std::string Name, int signGrade, int execGrade);
	Form(const Form& copy);
	Form&	operator=(const Form& rhs);
	~Form();


	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void		beSigned(const Bureaucrat& signer);
};

std::ostream&	operator<<(const std::ostream stream, const Form& rhs) const;

#endif