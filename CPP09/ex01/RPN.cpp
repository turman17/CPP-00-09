#include "RPN.h"

void evaluateRPN(const std::string &input)
{
    std::istringstream iss(input);
    std::stack<int> intStack;
    std::string token;

    while (iss >> token)
    { // Tokenize the input based on spaces
        if (isdigit(token[0]) || (token.length() > 1 && isdigit(token[1])))
        {                                            // Check if token is a number (accounting for negative numbers)
            intStack.push(std::atoi(token.c_str())); // Convert token to int and push onto the stack
        }
        else
        { // Assume token is an operator (+, -, *, /)
            if (intStack.size() < 2)
            { // Error check: need at least two numbers to perform an operation
                std::cerr << "Invalid expression." << std::endl;
                return;
            }
            int val2 = intStack.top(); // Pop the top two values to apply the operator
            intStack.pop();
            int val1 = intStack.top();
            intStack.pop();

            switch (token[0])
            { // Apply the operation based on the operator
            case '+':
                intStack.push(val1 + val2);
                break;
            case '-':
                intStack.push(val1 - val2);
                break;
            case '*':
                intStack.push(val1 * val2);
                break;
            case '/':
                if (val2 == 0)
                {
                    std::cerr << "Division by zero." << std::endl;
                    return;
                }
                intStack.push(val1 / val2);
                break;
            default:
                std::cerr << "Unknown operator: " << token << std::endl;
                return;
            }
        }
    }

    if (intStack.size() != 1)
    { // At the end, there should be exactly one value on the stack: the result
        std::cerr << "Invalid expression." << std::endl;
        return;
    }

    std::cout << "Result: " << intStack.top() << std::endl; // Output the result
}

void start(char *str)
{
    std::string input(str);
    evaluateRPN(input);
}
