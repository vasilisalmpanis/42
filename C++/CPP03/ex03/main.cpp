#include "DiamondTrap.h"

int main(void) {
	DiamondTrap bla("vasilis");

	bla.whoAmI();
	bla.attack("1");
	bla.attack("2");

	std::cout << bla.getHp() << std::endl;
	std::cout << bla.getEp() << std::endl;
	std::cout << bla.getAd() << std::endl;
	std::cout << bla.getName() << std::endl;
	std::cout << bla.getAd() << std::endl;
}
