#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
public:
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();
    void addNumber(int toAdd);
    int shortestSpan();
    int longestSpan();
    template <typename T>
    void IalmostForgotThisShit(T begin, T end)
    {
        if (_cont.size() + std::distance(begin, end) > _n)
            throw std::exception();
        _cont.insert(_cont.end(), begin, end);
    }

private:
    Span();
    unsigned int _n;
    std::vector<int> _cont;
};

#endif