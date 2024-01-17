#pragma once
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	std::string	        _target;
    void                action() const;
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &);

	// Getters
	std::string         getTarget() const;

	// Public
};