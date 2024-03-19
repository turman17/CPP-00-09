#include "iter.h"



int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    std::string stringArray[5] = {"one", "two", "three", "four", "five"};

    std::cout << std::endl;
    std::cout << "intArray iterated with the print function: ";
    iter(intArray, 5, print);
    std::cout << "\n\n";

    std::cout << "stringArray iterated with the print function: ";
    iter(stringArray, 5, print);
    std::cout << "\n\n";
}