#include "Serializer.hpp"

int main(void)
{
    Data* data = new Data;
    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "data: " << data << std::endl;
    std::cout << "raw: " << raw << std::endl;
    Data* deserialized = Serializer::deserialize(raw);

    if (deserialized == NULL)
    {
        std::cout << "NULL" << std::endl;
        delete data;
        return (0);
    }
    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "n: " << deserialized->n << std::endl;
    std::cout << "s2: " << deserialized->s2 << std::endl;
    delete data;
    return 0;
}