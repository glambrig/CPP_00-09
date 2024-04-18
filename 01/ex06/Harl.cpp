#include "Harl.hpp"

void	Harl::_debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-"
		<< "cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I can't believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
		<< "I’ve been coming for years whereas you started working here last month."
		<< std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*ptr)(void) = NULL;
	int			which;
	std::string	arr[] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		which = i;
		if (level.compare(arr[i]) == 0)
			break ;
		if (i == 3)
			which = -1;
	}
	while (which < 4 || which == -1)
	{
		switch (which)
		{
			case 0:
				ptr = &Harl::_debug;
				break;
			case 1:
				ptr = &Harl::_info;
				break;
			case 2:
				ptr = &Harl::_warning;
				break;
			case 3:
				ptr = &Harl::_error;
				break;
		}
		which++;
		if (ptr != NULL)
			(this->*ptr)();
		else
		{
			std::cout << "You couldn't even enter a complaint properly! booooo" << std::endl;
			return ;
		}
	}
	
}