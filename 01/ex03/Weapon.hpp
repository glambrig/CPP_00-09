#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
	std::string	getType(void);
	void		setType(std::string newType);
	Weapon(std::string wep);
	Weapon();
private:
	std::string _type;
};
#endif