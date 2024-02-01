#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat created\n";
    this->brain = new Brain();
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat is copied\n";
}

Cat& Cat::operator=(const Cat &other) {
    std::cout << "Cats operator called\n";
    if(this != &other)
    {
        this->type = other.type;
        delete brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const {
    std::cout << "Cat sound: Meow!\n";
}
