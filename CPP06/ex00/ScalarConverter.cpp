#include "ScalarConverter.h"

ScalarConverter::ScalarConverter()
{
    std::cout << "def const called\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    std::cout << "Copy const called\n";
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
    if(this != &other)
    {
        *this = other;
    }
    return(*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "def destructor called\n";
}
