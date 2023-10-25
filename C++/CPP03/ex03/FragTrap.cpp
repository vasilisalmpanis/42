//
// Created by Vasileios Almpanis on 10/24/23.
//

#include "FragTrap.h"

FragTrap::FragTrap(void) {
	this->_name = "FragTrap";
	this->_ep = 100;
	this->_ad= 30;
	this->_hp = 100;
	std::cout << "FragTrap Default Constructor Called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap Constructor Called" << std::endl;
	setHp(100);
	setEp(100);
	setAd(30);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj): ClapTrap(obj._name) {
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap &FragTrap::operator=(FragTrap const &obj) {
	if (this != &obj)
	{ this->_hp = obj._hp;
		this->_ad = obj._ad;
		this->_ep = obj._ep;
	}
	return (*this);
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap object " << _name << " is high fiving." << std::endl;
}
