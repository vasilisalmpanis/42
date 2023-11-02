#pragma once
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
public:
	Cat();
	Cat(Cat const &);
	Cat &operator=(Cat const&);
	void makeSound() ;
	~Cat();
	std::string getIdea(int index);
	void setIdea(std::string, int index);
private:
	Brain *_ptr;
};
