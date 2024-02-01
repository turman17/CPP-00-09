#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string const& name);
    FragTrap(FragTrap const& other);
    FragTrap &operator=(FragTrap const& other);
    ~FragTrap();

    friend std::ostream& operator<<(std::ostream& os, const FragTrap& obj);
    void highFivesGuys(void);
};

#endif