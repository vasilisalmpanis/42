#pragma once
#include "ICharacter.h"
#include "AMateria.h"

class Character : public ICharacter {
	public:
		Character(std::string);
		Character(Character const &);
		~Character();
		Character &operator=(Character const &);
		void equip(AMateria *m);
		void unequip(int x);
		std::string const & getName() const;
		void use(int idx, ICharacter& target); 
	protected:
		AMateria *_ptr[4];
		std::string _name;
};
