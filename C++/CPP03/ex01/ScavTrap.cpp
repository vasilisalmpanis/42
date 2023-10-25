//
// Created by Vasileios Almpanis on 10/24/23.
//

#include "ScavTrap.h"


ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap Constructor Called" << std::endl;
	setHp(100);
	setEp(50);
	setAd(20);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(obj._name) {
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj) {
	if (this != &obj)
	{ this->_hp = obj._hp;
		this->_ad = obj._ad;
		this->_ep = obj._ep;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (_ep == 0)
	{
		std::cout << "ScavTrap object " + _name + " has no more EP to attack." << std::endl;
		return ;
	}
	--_ep;
	std::cout << "ScavTrap object " << _name << " attacks " << target << " and causing " << _ad << " points of damage." << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap Object " << _name << " is now in Gate Keeper Mode." << std::endl;
}
