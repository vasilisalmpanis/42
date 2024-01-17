#pragma once
# include "Bureaucrat.hpp"
# include <cstdlib>
# include <ios>
# include <iostream>
# include <fstream>


class Bureaucrat;

class AForm {
	const std::string	_name;
	bool     			_signed;
	const int			_gradeSign;
	const int			_gradeExec;
	virtual void		action() const = 0;
	public:
        AForm();
		AForm(std::string, int, int);
		AForm(const AForm &);
		virtual ~AForm();
		AForm &operator=(const AForm &);

		// Getters
		std::string 	getName() const;
		bool			getSigned() const;
		int				getGradeSign() const;
		int				getGradeExec() const;

		// Setters

		void			setSigned(bool value);

        // Exceptions
	    class GradeTooHighException : public std::exception {
	    	public:
	    		virtual const char* what() const throw();
	    } ;

	    class GradeTooLowException : public std::exception {
	    	public:
	    		virtual const char* what() const throw();
	    } ;
	    class FormNotSigned : public std::exception {
	    	public:
	    		virtual const char* what() const throw();
	    } ;

		// Public
		void			beSigned(Bureaucrat &);
		virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream & operator << (std::ostream &out, const AForm &obj);