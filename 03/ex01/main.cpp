#include "ScavTrap.hpp"

int main()
{
	// Create a ScavTrap object
	ScavTrap scav("Robo");
	
	std::cout << scav.getName() << " has " << scav.getEnergy() << " energy points." << std::endl;
	std::cout << scav.getName() << " has " << scav.getHealth() << " health points." << std::endl;
	std::cout << std::endl;

	scav.attack("BIG ENEMY");
	std::cout << scav.getName() << " has " << scav.getEnergy() << " energy points." << std::endl;
	scav.attack("BIG ENEMY");
	std::cout << scav.getName() << " has " << scav.getEnergy() << " energy points." << std::endl;
	scav.attack("ANOTHER ENEMY");
	std::cout << scav.getName() << " has " << scav.getEnergy() << " energy points." << std::endl;
	scav.attack("ANOTHER ENEMY");
	std::cout << scav.getName() << " has " << scav.getEnergy() << " energy points." << std::endl;
	
	scav.guardGate();

	// Test case 1: Repair with positive amount
	scav.beRepaired(10); // Expected output: scav Robo has repaired itself for 10 points of damage!
	std::cout << scav.getName() << " has " << scav.getHealth() << " health points." << std::endl;

	// Test case 2: Repair with zero amount
	scav.beRepaired(0); // Expected output: No output
	std::cout << scav.getName() << " has " << scav.getHealth() << " health points." << std::endl;

	// Test case 3: Repair with negative amount
	scav.beRepaired(-5); // Expected output: No output
	std::cout << scav.getName() << " has " << scav.getHealth() << " health points." << std::endl;

	// Test case 4: Repair when health or energy is zero
	scav.setHealth(0);
	scav.setEnergy(0);
	scav.beRepaired(10); // Expected output: No output

	return 0;
}