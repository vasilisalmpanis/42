#pragma once


#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);
	~WrongAnimal();
	std::string getType() const;
	void makeSound() const;

protected:
	std::string _type;	
};

