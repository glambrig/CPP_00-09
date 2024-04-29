#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
	int			_healthp;
	int			_energyp;
	int			_attdmg;
public:
	DiamondTrap();
	DiamondTrap(const std::string Name);
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap& operator=(const DiamondTrap& rhs);
	~DiamondTrap();

	void	attack(const std::string&);
	void	whoAmI();
};

#endif