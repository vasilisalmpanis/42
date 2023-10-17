//
// Created by Vasileios Almpanis on 10/17/23.
//

#include "HumanB.h"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}