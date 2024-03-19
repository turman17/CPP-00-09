#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*f)(T const &))
{
    for(int i = 0; i < len; i++)
        f(arr[i]);
}

template <typename T>

void print(T const &c)
{
    std::cout << c << ", ";
}

#endif