#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Constructor called." << std::endl;
	this->_name = "NO NAME :(";
	this->_healthp = 100;
	this->_energyp = 100;
	this->_attdmg = 30;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	std::cout << "FragTrap Constructor called." << std::endl;
	this->_healthp = 100;
	this->_energyp = 100;
	this->_attdmg = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap Copy constructor called." << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	this->_name = rhs._name;
	this->_healthp = rhs._healthp;
	this->_energyp = rhs._energyp;
	this->_attdmg = rhs._attdmg;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_healthp <= 0 || this->_energyp<= 0)
		return ;
	std::cout << "FragTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attdmg << " points of damage! ow ow ow ow..."
		<< std::endl;
	this->_energyp--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "hi 5... high fiVE PLease!! HIGH FIVE. guys... pls..."
		<< std::endl;
}
