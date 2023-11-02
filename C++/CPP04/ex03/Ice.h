#pragma once
#include "AMateria.h"

class Ice : public AMateria{
public:
    Ice();
    Ice(Ice const &);
    Ice &operator=(Ice const &);
    ~Ice();
    AMateria* clone() const;
    // void use(ICharacter& target);
};
