#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat created\n";
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat is copied\n";
}

Cat& Cat::operator=(const Cat &other) {
    Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const {
    std::cout << "Cat sound: Meow!\n";
}
