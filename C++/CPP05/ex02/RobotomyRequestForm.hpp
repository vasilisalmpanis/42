#pragma once
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	std::string	_target;
    void        action() const;
    int         _rand() const;
	int			nameToNumber() const;
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);

	// Getters
	std::string getTarget() const;

	// Public
};