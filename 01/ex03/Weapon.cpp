#include "Weapon.hpp"

std::string	Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}

Weapon::Weapon(std::string wep)
{
	setType(wep);
}	

Weapon::Weapon(void)
{

}