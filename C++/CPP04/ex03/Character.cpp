#include "Character.h"
#include "AMateria.h"

Character::Character(std::string name) : _name(name){
	for (int i = 0; i < 4; ++i)
	{
		this->_ptr[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(Character const &obj) {
	*this = obj; 
}

Character &Character::operator=(Character const &obj) {
	if (this != &obj)
	{
		this->_name = obj._name;
		for (int i = 0; i < 4; ++i) {
			this->_ptr[i] = obj._ptr[i];
		}
	}
	return *this;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (!this->_ptr[i])
		{
			this->_ptr[i] = m;
			return;
		}
	}
	std::cout << "Cannot equip inventory is full" << std::endl;
}


void Character::unequip(int x) {
	for (int i = 0; i < 4; ++i) {
		if (i == x)
		{
			if (this->_ptr[x])
			{
				this->_ptr[i] = NULL;
				return ;
			}
		}
	}
	std::cout << "Cannot unequip" << std::endl;
}


std::string const & Character::getName() const {
	return (this->_name);	
} 



void Character::use(int idx, ICharacter& target) {
	if (idx > -1 && idx < 4)
	{
		if (this->_ptr[idx])
		{
			this->_ptr[idx]->use(target);
		}
	}
} 


