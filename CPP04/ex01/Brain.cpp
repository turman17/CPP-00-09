#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain created\n";
}

Brain::Brain(Brain const& other){
    std::cout << "Brain is copied\n";
    *this = other;
}

Brain &Brain::operator=(Brain const& other){
    if(this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed\n";
}