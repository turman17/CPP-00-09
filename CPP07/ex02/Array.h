#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
    Array() : _elements(NULL), _arraySize(0) {}

    Array(unsigned int size) : _arraySize(size)
    {
        _elements = new T[size]();
    }

    Array(Array const &other) : _elements(NULL), _arraySize(other._arraySize)
    {
        *this = other;
    }

    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            delete[] _elements;
            _arraySize = other._arraySize;
            _elements = new T[_arraySize];
            for (unsigned int i = 0; i < _arraySize; i++)
            {
                _elements[i] = other._elements[i];
            }
        }
        return *this;
    }

    ~Array()
    {
        delete[] _elements;
    }

    T &operator[](unsigned int index)
    {
        if (index >= _arraySize)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _arraySize)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    unsigned int size() const
    {
        return _arraySize;
    }

private:
    T *_elements;
    unsigned int _arraySize;
};

#endif
