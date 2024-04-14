#include "RPN.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

void evaluateRPN(const std::string &input)
{
    std::istringstream iss(input);
    std::stack<int> intStack;
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
        {
            if (intStack.size() < 2)
            {
                error();
                return;
            }
            int a = intStack.top();
            intStack.pop();
            int b = intStack.top();
            intStack.pop();

            if (token == "+")
                intStack.push(b + a);
            else if (token == "-")
                intStack.push(b - a);
            else if (token == "*")
                intStack.push(b * a);
            else if (token == "/")
            {
                if (a == 0)
                {
                    error();
                    return;
                }
                intStack.push(b / a);
            }
            else if (token == "%")
            {
                if (a == 0)
                {
                    error();
                    return;
                }
                intStack.push(b % a);
            }
        }
        else
        {
            char *endPtr;
            long num = std::strtol(token.c_str(), &endPtr, 10);
            if (*endPtr != '\0')
            {
                error();
                return;
            }
            intStack.push(static_cast<int>(num));
        }
    }

    if (intStack.size() != 1)
    {
        error();
        return;
    }

    std::cout << intStack.top() << std::endl;
}

void start(char *str)
{
    std::string input(str);
    evaluateRPN(input);
}