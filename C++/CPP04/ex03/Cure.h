#pragma once
#include "AMateria.h"

class Cure : public AMateria
{
public:
    Cure();
    Cure(Cure const &);
    Cure &operator=(Cure const &);
    ~Cure();
    AMateria *clone() const;
    void use(ICharacter& target);
};
