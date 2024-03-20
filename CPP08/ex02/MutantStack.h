#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <deque>
#include <iostream>


template <typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack(){};
    MutantStack(MutantStack const &other) { (void)other; };
    MutantStack &operator=(MutantStack const &other)
    {
        (void)other;
        return *this;
    };
    ~MutantStack(){};

    typedef typename Container::iterator iterator;

    iterator begin()
    {
        return std::stack<T, Container>::c.begin();
    }

    iterator end()
    {
        return std::stack<T, Container>::c.end();
    }

private:
};

#endif