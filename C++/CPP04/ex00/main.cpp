#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* meta2 = new WrongAnimal(); 
	const WrongAnimal* i2 = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "Wrong ones" << std::endl;
	i2->makeSound();
	meta2->makeSound();
	delete meta;
	delete i;
	delete j;
	delete i2;
	delete meta2;
	return 0;
}
