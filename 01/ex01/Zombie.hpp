#include <iostream>

class	Zombie
{
public:
	Zombie() : name("") {};
	Zombie(std::string name, bool toggle);
	~Zombie(void);
	void	announce(void);
	Zombie 	*newZombie(std::string name);

	std::string	getName(void);
private:
	std::string	name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
Zombie*	zombieHorde(int N, std::string name);