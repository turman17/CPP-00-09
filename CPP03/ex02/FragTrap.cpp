#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_Frag") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap name constructor called\n";   
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other) {}

FragTrap &FragTrap::operator=(FragTrap const &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "FragTrap copy assignment operator called\n";
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap requests a positive high five!\n";
}

std::ostream& operator<<(std::ostream& os, const FragTrap& obj) {
    os << "FragTrap '" << obj._name << "' with HP: " << obj._hitPoints
       << ", Energy: " << obj._energyPoints << ", Attack Damage: " << obj._attackDamage;
    return os;
}
