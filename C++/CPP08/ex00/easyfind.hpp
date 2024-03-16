#pragma once

#include <iostream>
#include <algorithm>
#include <exception>

template <typename T>
void easyfind(T container, int number)
{
    typename T::iterator it = std::find(container.begin(), container.end(), number);
    if (it != container.end())
        std::cout << "Found " << *it << std::endl;
    else
        throw std::runtime_error("Not found");
}