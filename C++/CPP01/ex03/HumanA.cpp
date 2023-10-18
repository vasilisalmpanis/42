//
// Created by Vasileios Almpanis on 10/17/23.
//

#include "HumanA.h"

HumanA::HumanA(std::string name1, Weapon   &weapon1) : _name(name1), _weapon(weapon1) {
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}