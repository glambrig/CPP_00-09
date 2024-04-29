#include "ClapTrap.hpp"

int main()
{
	// Create a ClapTrap object
	ClapTrap clapTrap("Robo");
	
	std::cout << "claptrap has " << clapTrap.getEnergy() << " energy points." << std::endl;
	std::cout << "claptrap has " << clapTrap.getHealth() << " health points." << std::endl;
	std::cout << std::endl;

	clapTrap.attack("BIG ENEMY");
	std::cout << "claptrap has " << clapTrap.getEnergy() << " energy points." << std::endl;
	clapTrap.attack("BIG ENEMY");
	std::cout << "claptrap has " << clapTrap.getEnergy() << " energy points." << std::endl;
	clapTrap.attack("ANOTHER ENEMY");
	std::cout << "claptrap has " << clapTrap.getEnergy() << " energy points." << std::endl;
	clapTrap.attack("ANOTHER ENEMY");
	std::cout << "claptrap has " << clapTrap.getEnergy() << " energy points." << std::endl;
	
	// Test case 1: Repair with positive amount
	clapTrap.beRepaired(10); // Expected output: ClapTrap Robo has repaired itself for 10 points of damage!
	std::cout << "claptrap has " << clapTrap.getHealth() << " health points." << std::endl;

	// Test case 2: Repair with zero amount
	clapTrap.beRepaired(0); // Expected output: No output
	std::cout << "claptrap has " << clapTrap.getHealth() << " health points." << std::endl;

	// Test case 3: Repair with negative amount
	clapTrap.beRepaired(-5); // Expected output: No output
	std::cout << "claptrap has " << clapTrap.getHealth() << " health points." << std::endl;

	// Test case 4: Repair when health or energy is zero
	clapTrap.setHealth(0);
	clapTrap.setEnergy(0);
	clapTrap.beRepaired(10); // Expected output: No output

	return 0;
}