#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	Cat();
	Cat(Cat const &);
	Cat &operator=(Cat const&);
	void makeSound() const;
	~Cat();
};

