#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal created\n";
    this->type = "Animal";
}

Animal::Animal(const Animal &other) {
    std::cout << "Animal is copied\n";
    *this = other;
}

Animal& Animal::operator=(const Animal &other) {
    std::cout << "Assignation operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

void Animal::makeSound() const {
    std::cout << "Animal sound: bebebebebebe\n";
}

std::string Animal::getType() const {
    return this->type;
}
