#ifndef WRONGWANIMAL_HPP
#define WRONGWANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};

#endif
