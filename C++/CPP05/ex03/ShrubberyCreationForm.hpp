#pragma once
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	std::string	_target;
	void		action() const;
	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

	// Getters
	std::string getTarget() const;

	// Public
};