#include "ClapTrap.hpp"

int main() {
    // Creating a ClapTrap instance with the default constructor
    ClapTrap defaultClapTrap;
    defaultClapTrap.attack("Enemy1");
    defaultClapTrap.takeDamage(4);
    defaultClapTrap.beRepaired(2);

    std::cout << std::endl;

    // Creating a ClapTrap instance with a custom name
    ClapTrap namedClapTrap("John");
    namedClapTrap.attack("Enemy2");
    namedClapTrap.takeDamage(3);
    namedClapTrap.beRepaired(1);

    std::cout << std::endl;

    // Copy constructing a ClapTrap instance from the named one
    ClapTrap copiedClapTrap(namedClapTrap);
    copiedClapTrap.attack("Enemy3");

    std::cout << std::endl;

    // Assigning one ClapTrap to another
    defaultClapTrap = copiedClapTrap;
    defaultClapTrap.attack("Enemy4");

    return 0;
}
