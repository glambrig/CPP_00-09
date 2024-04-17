#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class	HumanB
{
public:
	void		attack(void);
	std::string	getName(void);
	Weapon		getWeapon(void);
	void		setName(std::string name);
	void		setWeapon(Weapon &newWeapon);
	HumanB(std::string newName);
	HumanB(std::string newName, Weapon *weapon);
private:
	Weapon		*_weapon;
	std::string	_name;
};
#endif