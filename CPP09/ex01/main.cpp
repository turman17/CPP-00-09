#include "RPN.h"

void error()
{
    std::cout << "Error\n";
}

int main(int ac, char **av)
{
    if(ac != 2)
    {
        error();
        return 1;
    }
    start(av[1]);
    
    return 0;
}