#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;
public:
    void setter(std::string newName);
    ~Zombie();
    void announce();
};

#endif
