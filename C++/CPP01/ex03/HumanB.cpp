//
// Created by Vasileios Almpanis on 10/17/23.
//

#include "HumanB.h"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	if (this->weapon == NULL )
	{
		std::cout << name << " cannot attack without a weapon " << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
