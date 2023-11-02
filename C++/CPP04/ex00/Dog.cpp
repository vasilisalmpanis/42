#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(Dog const &obj) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog &Dog::operator=(Dog const &obj) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

Dog::~Dog(){
	std::cout << "DF D" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}
