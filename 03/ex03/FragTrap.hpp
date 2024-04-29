#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string Name);
	FragTrap(const FragTrap& copy);
	FragTrap& operator=(const FragTrap& rhs);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys(void);
	std::string	_name;
	int			_healthp;
	int			_energyp;
	int			_attdmg;
};

#endif