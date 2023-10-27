#include "DiamondTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include <stdio.h>
int main(void) {
	DiamondTrap a("hello");
	std::cout <<  a.getEp() << std::endl;;
	std::cout << a.getHp() << std::endl;
	std::cout << a.getAd() << std::endl;
	a.attack("hello");
	a.whoAmI();
	a.attack("radom");
	a.attack("radom");

	for (int i = 0; i <= 51; i++)
	{
		a.beRepaired(10);
	}

}
