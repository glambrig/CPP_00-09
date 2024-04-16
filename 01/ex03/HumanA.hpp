#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
public:
	void		attack(void);
	std::string	getName(void);
	Weapon		&getWeapon(void);
	void		setName(std::string name);
	// void		setWeapon(Weapon &newWeapon);
	HumanA(std::string name, Weapon &weapon);
private:
	Weapon		&_weapon;
	std::string	_name;
};
#endif