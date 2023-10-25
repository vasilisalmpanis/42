#ifndef FlagTrap_HPP
#define FlagTrap_HPP
#include "ClapTrap.h"

class FlagTrap: public ClapTrap {
private:

public:
	void highFiveGuys(void);
	FlagTrap(std::string name);
	~FlagTrap();
	FlagTrap(FlagTrap const &obj);
	FlagTrap &operator=(const FlagTrap &obj);
	void attack(const std::string& target);
};

#endif
