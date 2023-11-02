#pragma once


#include "Brain.h"
#include <iostream>

class Animal {
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &);
	Animal &operator=(const Animal &);
	virtual	~Animal();
	std::string getType() const;
	virtual void makeSound() = 0;
protected:
	std::string _type;	
};

