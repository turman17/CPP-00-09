#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <string>
#include <ctime>
#include "Data.h"

typedef unsigned long int uintptr_t;

class Serialize
{
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
private:
    Serialize();
    Serialize(Serialize const &other);
    Serialize &operator=(Serialize const& other);
    ~Serialize();
};

#endif