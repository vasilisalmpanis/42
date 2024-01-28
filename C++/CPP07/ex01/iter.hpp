#pragma once
#include <iostream>


template <typename T> // is the same as template <class T>
void iter(T *array, size_t length, void (*f) (T &array))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T> // is the same as template <class T>
T addOne(T array)
{
    return(++array);
}

template <typename T> // is the same as template <class T>
void print(T array)
{
    std::cout << addOne(array) << std::endl;
}