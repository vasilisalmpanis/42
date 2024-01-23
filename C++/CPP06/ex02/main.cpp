#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base baseObject;
    Base *base = baseObject.generate();
    base->identify(base);
    base->identify(*base);
    delete base;
    return 0;
}