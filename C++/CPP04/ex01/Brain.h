#pragma once
#include <iostream>

class Brain {
public:
	Brain();
	Brain(const Brain &);
	Brain &operator=(Brain const &);
	~Brain();
	void setIdeas(std::string idea, int index);
	std::string getIdeas(int index) const;

private:
	std::string ideas[100];
};

