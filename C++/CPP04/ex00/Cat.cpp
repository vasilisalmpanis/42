#include "Cat.h"
#include "Animal.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat() {
	std::cout << "DF C" << std::endl;
}


Cat::Cat(Cat const &obj) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Cat &Cat::operator=(Cat const &obj) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}


void Cat::makeSound() const {
	std::cout << "Meooooooow" << std::endl;
}
