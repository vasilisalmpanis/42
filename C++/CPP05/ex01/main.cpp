#include <iostream>
#include "Form.hpp"

int main() {
    Form f1("first", 10, 10);
    Form f2("second", 10, 15);
    Form copy(f1);

    std::cout << f1;
    std::cout << f2;
    std::cout << copy;
    std::cout << "copy assignmed \n\n";
    copy = f2;
    std::cout << copy;
    //Execeptions
    try
    {
        Form exception("hello", 10, -10);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form exception("hello", 10, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat me("vasileios", 11);
    try
    {
        f1.beSigned(me);
        f2.beSigned(me);
        copy.beSigned(me);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form last("Its working see?", 20, 20);
        try
    {
        last.beSigned(me);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}