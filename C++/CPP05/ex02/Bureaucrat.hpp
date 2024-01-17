#pragma once
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string   name;
	int                 grade;
public:
	// Private
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	// Getters
	std::string getName() const;
	int         getGrade() const;

	// Public
	void        incrementGrade();
	void        decrementGrade();
	void		signForm(const AForm &);
	void		executeForm(AForm const & form);

	// Exceptions

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	} ;
	
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	} ;
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &obj);