#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>

class ScalarConverter {
public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const& other);
    ScalarConverter &operator=(ScalarConverter const& other);
    ~ScalarConverter();
private:
};
#endif