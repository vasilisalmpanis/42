#include "Cure.h"
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
    AMateria* tmp1;
    tmp1 = new Cure();
    AMateria *other1;

    other1 = tmp1->clone();
    std::cout << other1->getType() << std::endl;
}
