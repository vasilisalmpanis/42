#include "easyfind.hpp"
#include <vector>

int main(void)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    easyfind(v, 2);
    try
    {
        easyfind(v, 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}