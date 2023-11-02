#include "WrongCat.h"
#include "WrongAnimal.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &obj) {
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat &WrongCat::operator=(WrongCat const &obj) {
	std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}


void WrongCat::makeSound() const {
	std::cout << "Meooooooow" << std::endl;
}
