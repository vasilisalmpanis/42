#pragma once
#include <iostream>
#include "ICharacter.h"


class ICharacter;

class AMateria
{
public:
    AMateria(std::string const & type);
    AMateria(AMateria const &);
    AMateria &operator=(AMateria const &);
    virtual ~AMateria();
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
protected:
    std::string _type;
};
