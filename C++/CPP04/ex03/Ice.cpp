#include "Ice.h"

Ice::Ice() : AMateria("ice"){
    std::cout << "Ice constructor called" << std::endl;
}
Ice::Ice(Ice const &obj) : AMateria(obj.getType()) {
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &obj) {
    std::cout << "Ice copy assignemnet operator called" << std::endl;
    this->_type = obj._type;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return (new Ice());
}
// void use(ICharacter& target)