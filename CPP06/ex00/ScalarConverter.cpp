#include "ScalarConverter.h"

ScalarConverter::ScalarConverter()
{
    std::cout << "def const called\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    (void)other;
    std::cout << "Copy const called\n";
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "def destructor called\n";
}

bool isNumber(const std::string &s)
{
    size_t start = 0;
    if (s.empty())
        return false;
    if (s[0] == '-' || s[0] == '+')
        start = 1;

    bool hasDigits = false;
    bool hasDot = false;
    for (size_t i = start; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            if (hasDot || i == start || i == s.size() - 1)
                return false;
            hasDot = true;
        }
        else if (!isdigit(s[i]))
            return false;
        else
            hasDigits = true;
    }
    return hasDigits;
}

int getType(const std::string &toConvert)
{
    if (toConvert.find_first_of('.') != std::string::npos &&
        toConvert[toConvert.length() - 1] == 'f' &&
        isNumber(toConvert.substr(0, toConvert.length() - 1)))
    {
        return FLOAT;
    }
    else if (toConvert.find_first_of('.') != std::string::npos && isNumber(toConvert))
    {
        return DOUBLE;
    }
    else if (toConvert == "-inff" || toConvert == "+inff" || toConvert == "inff" || toConvert == "-inf" || toConvert == "+inf" || toConvert == "inf" || toConvert == "nanf" || toConvert == "nan")
        return INFINITE;
    else if (toConvert.length() == 1 && !isdigit(toConvert[0]))
        return CHAR;
    else if (isNumber(toConvert))
        return INT;
    else
        return INVALID;
}

void fromFloat(std::string toConvert)
{
    try
    {
        float converted = std::atof(toConvert.c_str());
        std::cout << "char: " << (std::isprint(converted) ? static_cast<char>(converted) : '?') << std::endl;
        std::cout << "int: " << static_cast<int>(converted) << std::endl;
        std::cout << "float: " << converted << "f" << std::endl;
        std::cout << "double:  " << static_cast<double>(converted) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: imposible" << std::endl;
        std::cout << "float: imposible" << std::endl;
        std::cout << "double:  imposible" << std::endl;
    }
}

void fromInt(std::string toConvert)
{
    try
    {
        int converted = std::atoi(toConvert.c_str());
        std::cout << "char: " << (std::isprint(converted) ? static_cast<char>(converted) : '?') << std::endl;
        std::cout << "int: " << converted << std::endl;
        std::cout << "float: " << static_cast<float>(converted) << "f" << std::endl;
        std::cout << "double:  " << static_cast<double>(converted) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: imposible" << std::endl;
        std::cout << "float: imposible" << std::endl;
        std::cout << "double:  imposible" << std::endl;
    }
}

void fromDouble(std::string toConvert)
{
    try
    {
        float converted = std::atof(toConvert.c_str());
        std::cout << "char: " << (std::isprint(converted) ? static_cast<char>(converted) : '?') << std::endl;
        std::cout << "int: " << static_cast<int>(converted) << std::endl;
        std::cout << "float: " << converted << "f" << std::endl;
        std::cout << "double:  " << static_cast<double>(converted) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: imposible" << std::endl;
        std::cout << "float: imposible" << std::endl;
        std::cout << "double:  imposible" << std::endl;
    }
}

void fromChar(std::string toConvert)
{
    try
    {
        char converted = toConvert[0];

        std::cout << "char: " << converted << std::endl;
        std::cout << "int: " << static_cast<int>(converted) << std::endl;
        std::cout << "float: " << converted << "f" << std::endl;
        std::cout << "double:  " << static_cast<double>(converted) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: imposible" << std::endl;
        std::cout << "float: imposible" << std::endl;
        std::cout << "double:  imposible" << std::endl;
    }
}

void fromInfinite(std::string toConvert)
{
    bool isInf = toConvert == "inf" || toConvert == "+inf" || toConvert == "inff" || toConvert == "+inff" || toConvert == "-inf" || toConvert == "-inff";
    bool isNaN = toConvert == "nan" || toConvert == "nanf";
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (isInf)
    {
        std::cout << "float: " << (toConvert.find('f') == std::string::npos ? toConvert + "f" : toConvert) << std::endl;
        std::cout << "double: " << toConvert.erase(toConvert.find('f'), 1) << std::endl;
    }
    else if (isNaN)
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void ScalarConverter::convert(std::string toConvert)
{
    int type = getType(toConvert);
    if (type == INVALID)
    {
        std::cout << "char: imposible\nint: imposible\nfloat: imposible\ndouble: imposible\n";
        return;
    }
    switch (type)
    {
    case INFINITE:
        fromInfinite(toConvert);
        break;
    case FLOAT:
        fromFloat(toConvert);
        break;
    case INT:
        fromInt(toConvert);
        break;
    case DOUBLE:
        fromDouble(toConvert);
        break;
    case CHAR:
        fromChar(toConvert);
        break;
        
    }
}
