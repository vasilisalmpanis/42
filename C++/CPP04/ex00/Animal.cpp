#include "Animal.h"
#include <iostream>

Animal::Animal() : _type("Animal"){
	std::cout << "Animal Default Construtor Called." << std::endl;
}


Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal Construtor Called." << std::endl;
}

Animal::Animal(Animal const &obj) : _type(obj._type){
	std::cout << "Animal Copy Construtor Called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor Called." << std::endl;
}

Animal &Animal::operator=(const Animal &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj){
		_type = obj._type;
	}
	return (*this);
}


void Animal::makeSound() const {
	std::cout << "Random Animal Noises" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
