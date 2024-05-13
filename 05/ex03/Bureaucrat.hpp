#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class	Bureaucrat
{
private:
	std::string const	_name;
	int		_grade;
	Bureaucrat();
public:
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrGrade(void);
	void		decrGrade(void);
	void		signForm(AForm& form);
	void		executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& rhs);

#endif