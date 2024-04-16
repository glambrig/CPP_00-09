#include "Weapon.hpp"
#include "HumanA.hpp"

std::string	HumanA::getName(void)
{
	return (_name);
}

Weapon	&HumanA::getWeapon(void)
{
	return (_weapon);
}

void	HumanA::setName(std::string newName)
{
	_name = newName;
}

void	HumanA::attack(void)
{
	std::cout << getName() << " attacks with their "
		<< _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
	
}
