#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
    ScavTrap();
    ScavTrap(std::string const& name);
    ScavTrap(ScavTrap const& other);
    ScavTrap &operator=(ScavTrap const& other);
    ~ScavTrap();

    friend std::ostream& operator<<(std::ostream& os, const ScavTrap& obj);
    // void attack(const std::string& target);
    void guardGate();
private:
};

#endif