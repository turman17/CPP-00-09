#include " Zombie.hpp"
#include <iostream>

void Zombie::setter(std::string newName)
{
    this->name = newName;
    std::cout << "Zombie was created " << name << "\n";
}

Zombie::~Zombie()
{
    std::cout << "Zombie is gone\n";
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
