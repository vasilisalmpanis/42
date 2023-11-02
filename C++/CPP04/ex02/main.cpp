#include "Animal.h"
#include "Brain.h"
#include "Cat.h"
#include "Dog.h"

int main()
{

// std::cout << "LEAK TEST\n" << std::endl;
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// delete j;
// delete i;

// std::cout << "\nDOG TEST\n" << std::endl;
// Cat something;
// something.setIdea("test", 2);
// {
//     Cat tmp = something;
//     std::cout << tmp.getIdea(2) << std::endl;
// }
// std::cout << something.getIdea(2) << std::endl;
// std::cout << "\nBRAIN TEST\n" << std::endl;
// Brain *test = new Brain();
// test->setIdeas("alrkhgkjsdfhgkjsdgh", 0);
// std::cout << test->getIdeas(0) << std::endl;
// delete test;
// Cat b;
// Cat a;
// Cat c(b);
// a.setIdea("idea", 2);
// std::cout << a.getIdea(2) << "\n";
// b = a;
Cat one;
Animal& two = one;
two.makeSound();
one.setIdea("sdkfjhgkjsdfhg", 0);
std::cout << one.getIdea(0) << std::endl;
{
    Cat two = one;
    std::cout << two.getIdea(0) << std::endl;
}
std::cout << one.getIdea(0) << std::endl;
return 0;
}
