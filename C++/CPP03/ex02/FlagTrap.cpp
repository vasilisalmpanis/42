//
// Created by Vasileios Almpanis on 10/24/23.
//

#include "FlagTrap.h"

FlagTrap::FlagTrap(std::string name) : ClapTrap(name){
	std::cout << "FlagTrap Default Constructor Called" << std::endl;
	setHp(100);
	setEp(100);
	setAd(30);
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

void FlagTrap::attack(const std::string& target) {
	for (int i = 0; i < _ad; ++i) {
		if (_ep <= 0)
		{
			std::cout << "FlagTrap object " << _name << " has no more EP to attack " << target << std::endl;
			return ;
		}
		_ep--;
	}
	std::cout << "FlagTrap object " << _name << " attacks " << target << " and causing " << _ad << " points of damage." << std::endl;
}

void FlagTrap::highFiveGuys() {
	std::cout << "FlagTrap object " << _name << " is high fiving." << std::endl;
}
