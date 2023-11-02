#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
	std::cout << "WrongAnimal Default Construtor Called." << std::endl;
}


WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "WrongAnimal Construtor Called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj) : _type(obj._type){
	std::cout << "WrongAnimal Copy Construtor Called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor Called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj){
		_type = obj._type;
	}
	return (*this);
}


void WrongAnimal::makeSound() const {
	std::cout << "Random WrongAnimal Noises" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
