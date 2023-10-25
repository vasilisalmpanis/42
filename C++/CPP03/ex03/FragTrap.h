#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "ClapTrap.h"

class FragTrap: virtual public ClapTrap {
private:

public:
	void highFiveGuys(void);
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(FragTrap const &obj);
	FragTrap &operator=(const FragTrap &obj);
};

#endif
