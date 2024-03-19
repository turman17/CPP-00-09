#include "Serialize.hpp"

Serialize::Serialize()
{
    // std::cout <<"def const called\n";
}

Serialize::Serialize(Serialize const &other)
{
    (void)other;
    // std::cout <<"copy const called\n";
}

Serialize& Serialize::operator=(Serialize const &other)
{
    (void)other;
    return(*this);
}

Serialize::~Serialize()
{
    // std::cout <<"def destructor called\n";
}

uintptr_t Serialize::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}