#include "Cure.h"
#include "ICharacter.h"
#include "Ice.h"
#include "Character.h"
#include "MateriaSource.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	IMateriaSource* dst = new MateriaSource();
	Ice bla;
	Cure *cure = new Cure();
	src->learnMateria(&bla);
	src->learnMateria(&bla);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	dst->learnMateria(&bla);
	dst->learnMateria(&bla);
	dst->learnMateria(&bla);
	*src = *dst;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);
	bob->equip(tmp);
	bob->equip(tmp);
	bob->equip(tmp);
	bob->equip(tmp);
	bob->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	bob->use(3, *bob);
	bob->use(4, *bob);
	bob->use(-1, *bob);
	*me = *bob;
	delete bob;
	delete me;
	delete src;
	delete tmp;
	delete dst;
	delete cure;
	return 0;
}
