#include "Cure.h"

Cure::Cure() : AMateria("cure"){
    std::cout << "Cure constructor called" << std::endl;
}
Cure::Cure(Cure const &obj) : AMateria(obj.getType()) {
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &obj) {
    std::cout << "Cure copy assignemnet operator called" << std::endl;
    this->_type = obj._type;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
    return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
