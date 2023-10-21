#include "ClapTrap.h"

int main(void) {
	ClapTrap bla("vasilis");

	std::cout << bla.getName() << std::endl;
	bla.attack("hello");
	std::cout << bla.getEp() << std::endl;
}
