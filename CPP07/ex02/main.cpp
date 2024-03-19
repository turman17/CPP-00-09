#include "Array.h"
#include <iostream>

int main()
{
    // Test default constructor
    Array<int> defaultArray;
    std::cout << "Default array size: " << defaultArray.size() << std::endl;

    // Test constructor with size
    Array<int> intArray(5);
    std::cout << "Initial array values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test element assignment
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
    }

    std::cout << "Modified array values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copiedArray = intArray;
    std::cout << "Copied array values: ";
    for (unsigned int i = 0; i < copiedArray.size(); i++)
    {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    // Modify original array and show copied array remains unchanged
    intArray[0] = 100;
    std::cout << "Modified original array first element: " << intArray[0] << std::endl;
    std::cout << "Copied array first element (should be unchanged): " << copiedArray[0] << std::endl;

    // Test for out-of-bounds access
    try
    {
        std::cout << "Attempting out-of-bounds access: ";
        std::cout << intArray[5] << std::endl; // This should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test array of strings
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = ", ";
    stringArray[2] = "World!";
    std::cout << "String array values: ";
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::cout << stringArray[i];
    }
    std::cout << std::endl;

    return 0;
}
