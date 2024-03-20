#include "Span.h"

#include <cstdlib> // For rand()
#include <ctime>   // For time()

int main()
{
    Span span(10000);
    Span span2(10000);

    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; ++i)
    {
        span.addNumber(std::rand());
    }

    try
    {
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::vector<int> v(10000);
    std::generate(v.begin(), v.end(), std::rand);
    span2.IalmostForgotThisShit(v.begin(), v.end());
    std::cout << span2.shortestSpan() << std::endl;
    std::cout << span2.longestSpan() << std::endl;
    return 0;
}