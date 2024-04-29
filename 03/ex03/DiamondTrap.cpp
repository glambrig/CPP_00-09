#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap constructor called." << std::endl;
	this->_name = "NO NAME :(";
	this->ClapTrap::_name = this->_name + "_clap_trap";
	this->_healthp = this->FragTrap::_healthp;
	this->_energyp = this->ScavTrap::_energyp;
	this->_attdmg = this->FragTrap::_attdmg;
}

DiamondTrap::DiamondTrap(const std::string Name) : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap constructor called." << std::endl;
	this->_name = Name;
	this->ClapTrap::_name = Name + "_clap_trap";
	this->_healthp = this->FragTrap::_healthp;
	this->_energyp = this->ScavTrap::_energyp;
	this->DiamondTrap::_attdmg = this->FragTrap::_attdmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(), FragTrap(), ScavTrap() 
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	this->_name = rhs._name;
	this->_healthp = rhs._healthp;
	this->_energyp = rhs._energyp;
	this->_attdmg = rhs._attdmg;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Who am I? My name is " << this->_name
		<< ", also known as " << this->ClapTrap::_name << std::endl;
}

int		DiamondTrap::getAttdmg(void)
{
	return (this->_attdmg);
}

std::string	DiamondTrap::getName(void)
{
	return (this->_name);
}
