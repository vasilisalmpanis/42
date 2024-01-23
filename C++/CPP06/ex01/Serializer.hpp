#pragma once
#include <stdint.h>
#include <string>
#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
} ;


class Serializer {
public:
    Serializer();
    virtual ~Serializer();
    Serializer(const Serializer& other);
    virtual Serializer& operator=(const Serializer& other) = 0;

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
