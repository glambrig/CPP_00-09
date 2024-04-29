#include "FragTrap.hpp"

int main()
{
	// Create a FragTrap object
	FragTrap Frag("Robo");
	
	std::cout << Frag.getName() << " has " << Frag.getEnergy() << " energy points." << std::endl;
	std::cout << Frag.getName() << " has " << Frag.getHealth() << " health points." << std::endl;
	std::cout << std::endl;

	Frag.attack("BIG ENEMY");
	std::cout << Frag.getName() << " has " << Frag.getEnergy() << " energy points." << std::endl;
	Frag.attack("BIG ENEMY");
	std::cout << Frag.getName() << " has " << Frag.getEnergy() << " energy points." << std::endl;
	Frag.attack("ANOTHER ENEMY");
	std::cout << Frag.getName() << " has " << Frag.getEnergy() << " energy points." << std::endl;
	Frag.attack("ANOTHER ENEMY");
	std::cout << Frag.getName() << " has " << Frag.getEnergy() << " energy points." << std::endl;
	
	Frag.highFIvesGuys();

	// Test case 1: Repair with positive amount
	Frag.beRepaired(10); // Expected output: Frag Robo has repaired itself for 10 points of damage!
	std::cout << Frag.getName() << " has " << Frag.getHealth() << " health points." << std::endl;

	// Test case 2: Repair with zero amount
	Frag.beRepaired(0); // Expected output: No output
	std::cout << Frag.getName() << " has " << Frag.getHealth() << " health points." << std::endl;

	// Test case 3: Repair with negative amount
	Frag.beRepaired(-5); // Expected output: No output
	std::cout << Frag.getName() << " has " << Frag.getHealth() << " health points." << std::endl;

	// Test case 4: Repair when health or energy is zero
	Frag.setHealth(0);
	Frag.setEnergy(0);
	Frag.beRepaired(10); // Expected output: No output

	return 0;
}