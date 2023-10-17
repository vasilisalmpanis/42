//
// Created by Vasileios Almpanis on 10/17/23.
//

#ifndef HumanA_HPP
#define HumanA_HPP
#include <iostream>
#include "Weapon.h"


class HumanA {
private:
	std::string name;
	Weapon   *weapon;
public:
	HumanA(std::string name1, Weapon    &weapon1);
	~HumanA();
	void attack();
};

#endif
