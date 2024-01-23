#pragma once
#include <string>
#include <iostream>

class Base
{
public:
    Base();
    virtual ~Base();
};

Base *generate(void);
void identify(Base *pointer);
void identify(Base &reference);