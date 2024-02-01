#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
    Brain();
    Brain(Brain const& other);
    Brain&operator=(Brain const& other);
    ~Brain();
private:
    std::string ideas[100];
};

#endif