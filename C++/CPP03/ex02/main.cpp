#include "FlagTrap.h"

int main(void) {
	FlagTrap bla("hello");
	bla.attack("vasilis");
	bla.highFiveGuys();
	FlagTrap other(bla);
	ClapTrap *ptr = new FlagTrap("other");
	for (int i = 0; i < 200; i++) {
		other.attack(ptr->getName());
	}
	delete ptr;
}
