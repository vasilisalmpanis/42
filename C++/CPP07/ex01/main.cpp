#include "iter.hpp"

int main(void)
{
    const int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    return 0;
}