#include "ClapTrap.h"

int main(void) {
	ClapTrap bla("vasilis");

	std::cout << bla.getName() << std::endl;
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.attack("hello");
	bla.beRepaired(20);
	std::cout << bla.getEp() << std::endl;
}
