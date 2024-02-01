#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << &string << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << "\n";

    std::cout << string << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";

    return 0;
}