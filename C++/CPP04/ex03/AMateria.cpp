#include "AMateria.h"

AMateria::AMateria(std::string const &type) : _type(type) {
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &obj) {
    std::cout << "AMateria copy constructor called" << std::endl;
   *this = obj;
}

AMateria &AMateria::operator=(AMateria const &obj) {
    std::cout << "AMateria copy assignment operator called" << std::endl;
    this->_type = obj._type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;  
}

std::string const &AMateria::getType() const {
    return (this->_type);
}
