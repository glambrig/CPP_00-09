#ifndef	AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class	AForm
{
private:
	std::string const	_name;
	int const			_execGrade;
	int					_signGrade;
	bool				_signed;
public:
	AForm();
	AForm(std::string Name, int signGrade, int execGrade);
	AForm(const AForm& copy);
	AForm&	operator=(const AForm& rhs);
	virtual ~AForm();
	std::string	getName() const;
	bool		getSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	void		beSigned(const Bureaucrat& signer);
	int			checkExecGrade(const Bureaucrat& b) const;
	virtual int execute(Bureaucrat const &executor) const = 0;
};

std::ostream&	operator<<(std::ostream& stream, const AForm& rhs);

#endif