#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib> // int
#include <cstdlib> // float, double
#include <cctype>  // for std::isdigit
#include <cmath>   // for std::isnan, std::isinf
#include <limits>
#include <iomanip>

#define INFINITE 5
#define INT 4
#define CHAR 3
#define DOUBLE 2
#define FLOAT 1
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define INVALID 7

class ScalarConverter {
public:
    static void convert(std::string toConvert);
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const& other);
    ScalarConverter &operator=(ScalarConverter const& other);
    ~ScalarConverter();
};
#endif