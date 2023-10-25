//
// Created by Vasileios Almpanis on 10/24/23.
//

#include "DiamondTrap.h"
#include "ClapTrap.h"
#include "FlagTrap.h"
#include "ScavTrap.h"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FlagTrap() {
};


DiamondTrap::DiamondTrap(std::string name) {
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap default constructor called." << std::endl;	
}


DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj): ClapTrap(obj._name) {
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &obj) {
	if (this != &obj)
	{ this->_hp = obj._hp;
		this->_ad = obj._ad;
		this->_ep = obj._ep;
		this->_hp = obj._hp;
	}
	return (*this);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " <<  this->_name << " ClapTrap name is " << ClapTrap::_name << std::endl;
}
