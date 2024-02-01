#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat created\n";
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "WrongCat is copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed\n";
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat sound: Meow!\n";
}
