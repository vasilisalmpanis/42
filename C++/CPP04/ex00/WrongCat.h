#pragma once
#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(WrongCat const &);
	WrongCat &operator=(WrongCat const&);
	void makeSound() const;
};

