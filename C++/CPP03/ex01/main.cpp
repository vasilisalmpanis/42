#include "ScavTrap.h"

int main(void) {
	ScavTrap bla("vasilis");

	std::cout << bla.getName() << std::endl;
	bla.attack("hello");
	bla.guardGate();
	std::cout << bla.getHp() << std::endl;
	std::cout << bla.getEp() << std::endl;
}
