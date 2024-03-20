#include "Span.h"

Span::Span(unsigned int n) : _n(n) {}
Span::Span() {}
Span::Span(Span const &other) : _n(other._n) {}

Span &Span::operator=(Span const &other)
{
    if(this != &other)
        this->_n = other._n;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int toAdd)
{
    if (_cont.capacity() == _cont.max_size())
        throw std::length_error("Maximum capacity reached");
    else
        _cont.push_back(toAdd);
}

int Span::longestSpan()
{
    if (_cont.size() < 2)
        throw std::logic_error("Length");
    else
    {
        std::vector<int> tmp = this->_cont;
        std::sort(tmp.begin(), tmp.end());
        return (tmp[tmp.size() - 1] - tmp[0]);
    }
}
int Span::shortestSpan(void)
{
    if (_cont.size() < 2)
        throw std::exception();
    std::vector<int> tmp = _cont;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (unsigned int i = 2; i < tmp.size(); i++)
        if (tmp[i] - tmp[i - 1] < shortest)
            shortest = tmp[i] - tmp[i - 1];
    return (shortest);
}