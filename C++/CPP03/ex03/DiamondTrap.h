#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP 
#include "ScavTrap.h"
#include "FragTrap.h"
class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(DiamondTrap const &obj);
	DiamondTrap &operator=(const DiamondTrap &obj);
	void whoAmI();
};

#endif
