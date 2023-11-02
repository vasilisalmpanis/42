#include "Ice.h"

int main()
{
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = new Ice();
    AMateria *other;

    other = tmp->clone();
    std::cout << other->getType() << std::endl;
}