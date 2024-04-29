#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _healthp(10), _energyp(10), _attdmg(0)
{
	std::cout << "Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _healthp(10), _energyp(10), _attdmg(0)
{
	std::cout << "Constructor called." << std::endl;
	this->_name = Name;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	this->_name = rhs._name;
	this->_healthp = rhs._healthp;
	this->_energyp = rhs._energyp;
	this->_attdmg = rhs._attdmg;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_healthp <= 0 || this->_energyp<= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attdmg << " points of damage!"
		<< std::endl;
	this->_energyp--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " has taken "
		<< amount << " points of damage!" << std::endl;
	this->_healthp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_healthp <= 0 || this->_energyp <= 0 || (int)amount <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " has repaired itself for "
		<< amount << " points of damage!" << std::endl;
	this->_healthp += amount;
	this->_energyp--;
}

void	ClapTrap::setHealth(int n)
{
	this->_healthp = n;
}

void	ClapTrap::setEnergy(int n)
{
	this->_energyp = n;
}

int	ClapTrap::getEnergy(void)
{
	return (this->_energyp);
}

int	ClapTrap::getHealth(void)
{
	return (this->_healthp);
}