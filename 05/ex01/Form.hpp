#ifndef	FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
private:
	std::string const	_name;
	int const			_execGrade;
	int					_signGrade;
	bool				_signed;
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
	// std::ostream&	operator<<(const std::ostream stream);
};

std::ostream&	operator<<(std::ostream& stream, const Form& rhs);

#endif