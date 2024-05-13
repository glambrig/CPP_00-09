#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>

class	RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm&	operator=(RobotomyRequestForm& rhs);
	~RobotomyRequestForm();

	virtual int	execute(const Bureaucrat& executor) const;
};

#endif