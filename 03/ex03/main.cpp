#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap("Robo");

    // Test the inherited ScavTrap methods
    diamondTrap.attack("Enemy");
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