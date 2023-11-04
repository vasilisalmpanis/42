#include "MateriaSource.h"

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
		for (int i = 0; i < 4; ++i) {
			this->_ptr[i] = obj._ptr[i];
		}
	}
	return *this;
}

