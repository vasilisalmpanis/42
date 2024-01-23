#include "A.hpp"
#include "C.hpp"
#include "B.hpp"

Base::Base(void) {}

Base::~Base(void) {}

Base *generate(void)
{
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

void identify(Base *pointer)
{
    try
    {
        if (dynamic_cast<A *>(pointer))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(pointer))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(pointer))
            std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void identify(Base &reference)
{
    try
    {
        if (dynamic_cast<A *>(&reference))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(&reference))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(&reference))
            std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}