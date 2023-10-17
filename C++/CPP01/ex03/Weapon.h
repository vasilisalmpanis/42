//
// Created by Vasileios Almpanis on 10/17/23.
//

#ifndef Weapon_HPP
#define Weapon_HPP
#include <iostream>

class Weapon {
private:
	std::string type;
public:
	void setType(std::string weapon);
	const std::string& getType(void) const;
	Weapon(std::string weapon);
	~Weapon();
};


#endif
