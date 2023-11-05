#include "MateriaSource.h"
#include "AMateria.h"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
		this->_ptr[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			if (this->_ptr[i] == this->_ptr[j])
				this->_ptr[j] = NULL;
		}
	}
	for (int i = 0; i < 4; ++i) {
		if (this->_ptr[i] != NULL)
			delete this->_ptr[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const &obj) {

	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &obj) {
	
	if (this != &obj)
	{
	    for (int i = 1; i < 4; ++i) {
	    	for (int j = i + 1; j < 4; ++j) {
	    		if (this->_ptr[i] == this->_ptr[j])
	    			this->_ptr[j] = NULL;
	    	}
	    }
	    for (int i = 0; i < 4; ++i) {
	    	if (this->_ptr[i] != NULL)
	    		delete this->_ptr[i];
	    }

		for (int i = 0; i < 4; ++i) {
			this->_ptr[i] = obj._ptr[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (!this->_ptr[i])
		{
			this->_ptr[i] = m->clone();
			return;
		}
	}
	std::cout << "No spots left to learn" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->_ptr[i] && this->_ptr[i]->getType() == type)
			return this->_ptr[i]->clone();
	}
	return 0;
}
