#pragma once
#include <iostream>

class AMateria
{
public:
    AMateria(std::string const & type);
    AMateria(AMateria const &);
    AMateria &operator=(AMateria const &);
    virtual ~AMateria();
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    // virtual void use(ICharacter& target) = 0;
protected:
    std::string _type;
};