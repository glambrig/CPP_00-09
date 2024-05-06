#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
private:
	std::string const	_name;
	int		_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string Name, int Grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrGrade(void);
	void		decrGrade(void);
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
	void		signForm(const Form& form) const;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& rhs);

#endif