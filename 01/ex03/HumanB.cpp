#include "Weapon.hpp"
#include "HumanB.hpp"

std::string	HumanB::getName(void)
{
	return (_name);
}

Weapon	HumanB::getWeapon(void)
{
	return (*_weapon);
}

void	HumanB::setName(std::string newName)
{
	_name = newName;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	_weapon = &newWeapon;
}

void	HumanB::attack(void)
{
	std::cout << getName() << " attacks with their "
		<< (*_weapon).getType() << std::endl;
}

HumanB::HumanB(std::string newName)
{
	setName(newName);
	_weapon = NULL;
}

HumanB::HumanB(std::string newName, Weapon *weapon)
{
	setName(newName);
	_weapon = weapon;
}