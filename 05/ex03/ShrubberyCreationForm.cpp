#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string s) : AForm(s, 145, 137)
{
	_target = s;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs)
{
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

int	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::fstream	file;
	std::string		res;

	try
	{
		if (this->getSigned() == false)
			throw ("ShrubberyCreationForm::FormNotSigned");
		if (checkExecGrade(executor) == 1)
			throw ("ShrubberyCreationForm::ExecutorGradeTooLow");
	}
	catch (const char *exception)
	{
		std::cerr << executor.getName() + " : " << exception << std::endl;
		return (1);
	}
	res = _target + "_shrubbery";
	file.open(res.c_str(), std::ios::out);
	file << 
	"	    .  .      +     .      .          ." << std::endl <<
	"     .       .      .     #       .           ." << std::endl <<
	"        .      .         ###            .      .      ." << std::endl <<
	"      .      .   \"#:. .:##\"##:. .:#\"  .      ." << std::endl <<
	"          .      . \"####\"###\"####\"  ." << std::endl <<
	"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl <<
	"  .             \"#########\"#########\"        .        ." << std::endl <<
	"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ." << std::endl <<
	"     .     .  \"#######\"\"##\"##\"\"#######\"                  ." << std::endl <<
	"                .\"##\"#####\"#####\"##\"           .      ." << std::endl <<
	"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ." << std::endl <<
	"      .     \"#######\"##\"#####\"##\"#######\"      .     ." << std::endl <<
	"    .    .     \"#####\"\"#######\"\"#####\"    .      ." << std::endl <<
	"            .     \"      000      \"    .     ." << std::endl <<
	"       .         .   .   000     .        .       ." << std::endl <<
	".. .. ..................O000O.................";
	file.close();
	return (0);
}