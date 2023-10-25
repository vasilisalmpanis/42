//
// Created by Vasileios Almpanis on 10/24/23.
//

#ifndef ScavTrap_HPP
#define ScavTrap_HPP
#include "ClapTrap.h"

class ScavTrap: virtual public ClapTrap {
private:

public:
	void guardGate(void);
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(ScavTrap const &obj);
	ScavTrap &operator=(const ScavTrap &obj);
	void attack(const std::string& target);
};



#endif
