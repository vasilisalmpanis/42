#pragma once
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include <exception>

class Intern {
        AForm *makeShrubbForm(std::string target);
        AForm *makeRoboForm(std::string target);
        AForm *makePresidentForm(std::string target);
    public:
        Intern();
        ~Intern();
        Intern(const Intern &);
        Intern &operator=(const Intern &);
        AForm *makeForm(std::string name, std::string target);
	    class FormTypeDoesntExist : public std::exception {
	    	public:
	    		virtual const char* what() const throw();
	    } ;
};