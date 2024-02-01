#include "Weapon.hpp"
#include "iostream"

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
}

Weapon::Weapon(const std::string& type)
{
    this->type = type;
}