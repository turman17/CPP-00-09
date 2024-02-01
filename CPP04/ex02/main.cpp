#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int number = 10;
    // AAnimal test;
    const Animal *animals[number];
    
    for (int i = 0; i < number; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < number; i++)
    {
        std::cout << i + 1 << ": ";
        animals[i]->makeSound();
    }
    for (int i = 0; i < number; i++)
    {
        delete animals[i];
    }
    {
        std::cout << std::endl << "Checking the copy constructors: " << std::endl;
        const 	Dog*	dog = new Dog;
        const	Animal* other = new Dog(*dog);
        dog->makeSound();
        other->makeSound();
        delete dog;
        delete other;
    }
}