#include "ClapTrap.h"
#include "ScavTrap.h"

int main(void) {
	ScavTrap bla("vasilis");

	std::cout << bla.getName() << std::endl;
	bla.attack("hello");
	bla.guardGate();
	std::cout << bla.getHp() << std::endl;
	std::cout << bla.getEp() << std::endl;
	ClapTrap *ptr = new ScavTrap("vasilis");
	for (int i = 0; i < 200; i++) {
		ptr->attack("hello");
	}
	delete ptr;
}
