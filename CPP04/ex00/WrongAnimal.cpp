#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal created\n";
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    std::cout << "WrongAnimal is copied\n";
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    std::cout << "Assignation operator called\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound: bebebebebebe\n";
}

std::string WrongAnimal::getType() const {
    return this->type;
}
