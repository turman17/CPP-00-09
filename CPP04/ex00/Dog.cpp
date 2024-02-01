#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog created\n";
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog is copied\n";
}

Dog& Dog::operator=(const Dog &other) {
    Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const {
    std::cout << "Dog sound: Woof!\n";
}
