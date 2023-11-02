#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Constructor Called" << std::endl;
	this->_ptr = new Brain;
}

Dog::Dog(Dog const &obj) {
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->_ptr = new Brain();
	if (this != &obj)
	{
		*this = obj;
	}
}

Dog &Dog::operator=(Dog const &obj) {
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
		*(this->_ptr) = *(obj._ptr);
	}
	return (*this);
}

Dog::~Dog(){
	delete this->_ptr;
	std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() {
	std::cout << "Woof Woof" << std::endl;
}
