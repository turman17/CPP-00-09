#include "BitcoinExchange.h"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << "<input.txt>" << std::endl;
        return -1;
    }
    try
    {
        parseData("data.csv", argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}