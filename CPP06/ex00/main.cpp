#include <iostream>

int main (int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Invalid number of arguments!\n";
        return 1;
    }
    
    return 0;
}