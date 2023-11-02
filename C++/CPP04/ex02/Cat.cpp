#include "Cat.h"
#include "Animal.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Constructor Called" << std::endl;
	this->_ptr = new Brain;
}

Cat::~Cat() {
	delete _ptr;
	std::cout << "Cat Destructor Called" << std::endl;
}


Cat::Cat(Cat const &obj) {
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->_ptr = new Brain();
	if (this != &obj)
	{
		*this = obj;
	}
}

std::string Cat::getIdea(int index) {
	if (index > -1 && index < 100)
		return (this->_ptr->getIdeas(index));
	return "";
}

void Cat::setIdea(std::string name, int index) {
	this->_ptr->setIdeas(name, index);
}


Cat &Cat::operator=(Cat const &obj) {
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
		*(this->_ptr) = *(obj._ptr);
	}
	return (*this);
}


void Cat::makeSound() {
	std::cout << "Meooooooow" << std::endl;
}
