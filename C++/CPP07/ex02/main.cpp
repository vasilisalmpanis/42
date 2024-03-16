#include "Array.hpp"

int main(void)
{
    const Array<int> intArray(10);
    //intArray[0] = 120;
    std::cout << intArray[0] << std::endl;

    Array<int> secondArray(1);
}
