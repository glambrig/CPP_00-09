#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Constructor called." << std::endl;
	this->_name = "NO NAME :(";
	this->_healthp = 100;
	this->_energyp = 50;
	this->_attdmg = 20;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "ScavTrap Constructor called." << std::endl;
	this->_healthp = 100;
	this->_energyp = 50;
	this->_attdmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap Copy constructor called." << std::endl;
	*this = copy;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	this->_name = rhs._name;
	this->_healthp = rhs._healthp;
	this->_energyp = rhs._energyp;
	this->_attdmg = rhs._attdmg;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_healthp <= 0 || this->_energyp<= 0)
		return ;
	std::cout << "ScavTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attdmg << " points of damage! THAT REAAAALLLY HURT!!"
		<< std::endl;
	this->_energyp--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode."
		<< std::endl;
}