#pragma once
# include "Bureaucrat.hpp"
# include <ios>

class Bureaucrat;

class Form {
	const std::string	_name;
	bool     			_signed;
	const int			_gradeSign;
	const int			_gradeExec;
	
	public:
        Form();
		Form(std::string, int, int);
		Form(const Form &);
		~Form();
		Form &operator=(const Form &);

		// Getters
		std::string 	getName() const;
		bool			getSigned() const;
		int				getGradeSign() const;
		int				getGradeExec() const;

        // Exceptions
	    class GradeTooHighException : public std::exception {
	    	public:
	    		virtual const char* what() const throw();
	    } ;

	    class GradeTooLowException : public std::exception {
	    	public:
	    		virtual const char* what() const throw();
	    } ;
		// Public
		void			beSigned(Bureaucrat &);
};

std::ostream & operator << (std::ostream &out, const Form &obj);