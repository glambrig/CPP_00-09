#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap("Robo");

	std::cout << diamondTrap.DiamondTrap::getName() << " has :" << std::endl
		<< diamondTrap.getHealth() << " hit points" << std::endl
		<< diamondTrap.getEnergy() << " energy points" << std::endl
		<< diamondTrap.DiamondTrap::getAttdmg() << " attack damage." << std::endl;

    // Test the inherited ScavTrap methods
    diamondTrap.attack("Enemy");
	std::cout << diamondTrap.getEnergy() << " energy points" << std::endl;
    diamondTrap.takeDamage(20);
    diamondTrap.beRepaired(10);

    // Test the inherited FragTrap methods
    diamondTrap.highFivesGuys();

    // Test the unique DiamondTrap methods
    diamondTrap.whoAmI();

    // Additional tests
    diamondTrap.attack("Another Enemy");
    diamondTrap.takeDamage(50);
    diamondTrap.beRepaired(30);
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();

    return 0;
}