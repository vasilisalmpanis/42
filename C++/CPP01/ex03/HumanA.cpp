//
// Created by Vasileios Almpanis on 10/17/23.
//

#include "HumanA.h"

HumanA::HumanA(std::string name1, Weapon   &weapon1) {
	this->name = name1;
	weapon = &weapon1;
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}