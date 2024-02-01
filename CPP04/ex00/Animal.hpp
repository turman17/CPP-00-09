#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
    Animal();
    Animal(Animal const& other);
    Animal& operator=(Animal const& other);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
protected:
    std::string type;
};

#endif
