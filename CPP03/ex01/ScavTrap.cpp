#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Default_Scav") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap name constructor called\n";   
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other) {}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap copy assignment operator called\n";
    return *this;
}


ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode.\n";
}


std::ostream& operator<<(std::ostream& os, const ScavTrap& obj) {
    os << "ScavTrap '" << obj._name << "' with HP: " << obj._hitPoints
       << ", Energy: " << obj._energyPoints << ", Attack Damage: " << obj._attackDamage;
    return os;
}
