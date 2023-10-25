#include "FlagTrap.h"

int main(void) {
	ClapTrap bla = FlagTrap("vasilis");
	bla.attack("vasilis");
	FlagTrap obj("robot");
	obj.highFiveGuys();
	obj.takeDamage(10);
}
