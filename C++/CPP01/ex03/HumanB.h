//
// Created by Vasileios Almpanis on 10/17/23.
//

#ifndef HumanB_HPP
#define HumanB_HPP
#include <iostream>
#include "Weapon.h"

class HumanB {
private:
	std::string name;
	Weapon   *weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
