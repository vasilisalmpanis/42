#pragma once

#include <iostream>

template <class T>
class Array
{
        T           *_array;
        unsigned int _size;
    public:
        Array(): _array(new T[0]), _size(0) {}
        Array(unsigned int n): _array(new T[n]), _size(n) {}
        Array(const Array &other): _array(new T[other.size]), _size(other.size) { *(this) = other; }
        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _array;
                _array = new T[other.size];
                _size = other.size;
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
        }
        ~Array() { delete[] _array; }
        T &operator[](unsigned int i)
        {
            if (i >= _size)
                throw std::exception();
            return (_array[i]);
        }
        const T &operator[](unsigned int i) const
        {
            if (i >= _size)
                throw std::exception();
            return (_array[i]);   
        }
        unsigned int size() const { return (_size); }
};
