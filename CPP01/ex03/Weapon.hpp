#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    private:
    std::string type;

    public:
    Weapon(const std::string& type);
    const std::string& getType() const;
    void setType(const std::string& Newtype);
};

#endif