#include "Brain.h"
#include <sstream>
#include <string>

Brain::Brain() {
	std::cout << "Brain Constructor Called" << std::endl;
	for (int i = -1; i < 100 ; ++i)
		this->setIdeas("empty", i);
}

Brain::~Brain() {
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain::Brain(Brain const &obj) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

void Brain::setIdeas(std::string idea, int index) {
	if (index > -1 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdeas(int index) const{
	if (index > -1 && index < 100)
		return (ideas[index]);
	return ("");
}

Brain &Brain::operator=(Brain const &obj) {
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = -1; i < 100; ++i)
			this->setIdeas(obj.getIdeas(i), i);
	}
	return (*this);
}
