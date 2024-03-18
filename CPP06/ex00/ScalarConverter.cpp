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
            {
                return false;
            }
            hasDot = true;
        }
        else if (!isdigit(s[i]))
        {
            return false;
        }
        else
        {
            hasDigits = true;
        }
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
        return INVALID; // Ensures all paths return a value
}

void toInt(const std::string &toConvert, int type)
{
    (void)type;
    long int number = std::atoll(toConvert.c_str());
    if (toConvert == "-inff" || toConvert == "+inff" || toConvert == "inff" || toConvert == "-inf" || toConvert == "+inf" || toConvert == "inf" || toConvert == "nanf" || toConvert == "nan")
        std::cout << "int: imposible" << std::endl;
    else if (number > MAX_INT)
        std::cout
            << "int: overflow\n";
    else
        std::cout << "int: " << number << std::endl;
}

void toChar(const std::string &toConvert, int type)
{
    if (toConvert == "-inff" || toConvert == "+inff" || toConvert == "inff" || toConvert == "-inf" || toConvert == "+inf" || toConvert == "inf" || toConvert == "nanf" || toConvert == "nan")
    {
        std::cout << "char: imposible" << std::endl;
        return;
    }
    else if (type != CHAR && type != INT)
    {
        std::cout << "char: non-displayable\n";
        return;
    }
    long int asciiCode = std::atol(toConvert.c_str());
    if (asciiCode >= 32 && asciiCode <= 126)
        std::cout << "char: '" << static_cast<char>(asciiCode) << "'\n";
    else
        std::cout << "char: non-displayable\n";
}

void infinityDetect(int number)
{
    if (number == std::numeric_limits<double>::infinity())
    {
        std::cout << "inf";
        return;
    }
    else if (number == -std::numeric_limits<double>::infinity())
    {
        std::cout << "-inf";
        return;
    }
    else if (std::isnan(number))
    {
        std::cout << "nan";
        return;
    }
}

void toDouble(const std::string &toConvert)
{
    double number = std::atof(toConvert.c_str());
    std::cout << "double: ";
    infinityDetect(number);
    std::cout << std::fixed << std::setprecision(1) << number;
    std::cout << std::endl;
}

void toFloat(std::string toConvert)
{
    float number = static_cast<float>(std::atof(toConvert.c_str()));

    std::cout << "float: ";

    infinityDetect(number);
    std::cout << std::fixed << std::setprecision(1) << number << 'f';
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string toConvert)
{
    int type = getType(toConvert);
    if (type == INVALID)
    {
        std::cout << "char: imposible\nint: imposible\nfloat: imposible\ndouble: imposible\n";
        return;
    }
    else
    {
        toInt(toConvert, type);
        toChar(toConvert, type);
        toFloat(toConvert);
        toDouble(toConvert);
    }
}
