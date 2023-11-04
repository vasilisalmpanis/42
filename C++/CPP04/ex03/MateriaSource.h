#pragma once
#include "AMateria.h"
#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria *_ptr[4];
};
