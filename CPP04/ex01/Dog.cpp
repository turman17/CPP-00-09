#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog created\n";
    this->brain = new Brain();
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog is copied\n";
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Dogs operator called\n";
    if(this != &other)
    {
        this->type = other.type;
        delete brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const {
    std::cout << "Dog sound: Woof!\n";
}
