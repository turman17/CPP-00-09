#include <iostream>
#include "ScalarConverter.h"

int main (int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Invalid number of arguments!\n";
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}