#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
private:
	std::string _name;
	int			_healthp;
	int			_energyp;
	int			_attdmg;

public:
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& rhs);
	void	setHealth(int n);
	void	setEnergy(int n);
	int		getEnergy(void);
	int		getHealth(void);

};

#endif