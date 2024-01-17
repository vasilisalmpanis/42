#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

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
	void		signForm(const Form &);

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