//
// Created by Vasileios Almpanis on 10/24/23.
//

#include "FlagTrap.h"
#include "ClapTrap.h"

FlagTrap::FlagTrap(void) : ClapTrap(){};

FlagTrap::FlagTrap(std::string name) : ClapTrap(name){
	std::cout << "FlagTrap Default Constructor Called" << std::endl;
	setHp(101);
	setEp(1);
	setAd(31);
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap Destructor called" << std::endl;
}

FlagTrap::FlagTrap(FlagTrap const &obj): ClapTrap(obj._name) {
	std::cout << "FlagTrap Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FlagTrap &FlagTrap::operator=(FlagTrap const &obj) {
	if (this != &obj)
	{ this->_hp = obj._hp;
		this->_ad = obj._ad;
		this->_ep = obj._ep;
	}
	return (*this);
}

void FlagTrap::highFiveGuys() {
	std::cout << "FlagTrap object " << _name << " is high fiving." << std::endl;

}
