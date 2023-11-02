#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
	Dog();
	Dog(Dog const &);
	Dog &operator=(Dog const&);
	void makeSound() const;
	~Dog();
};

