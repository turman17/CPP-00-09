#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T &cont, int number)
{
    typename T::iterator it;
    
    it = std::find(cont.begin(), cont.end(), number);

    if (it == cont.end())
        return -1;
    else
        return std::distance(cont.begin(), it);
}

#endif