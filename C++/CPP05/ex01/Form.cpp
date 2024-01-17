#include "Form.hpp"

Form::Form(): _name("empty"), _signed(false), _gradeSign(150), _gradeExec(150) {
	
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{

}

Form::Form(const Form &other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

// Getters

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int	Form::getGradeSign() const 
{
	return this->_gradeSign;
}

int Form::getGradeExec() const
{
	return this->_gradeExec;
}

// Exceptions

const char *Form::GradeTooLowException::what() const throw() {
    return ("Form Grade Too Low");
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Form Grade Too High");
}

// Public

void Form::beSigned(Bureaucrat &object)
{
	int grade = object.getGrade();

	if (this->_signed)
	{
		std::cout << "Form " << this->_name << " is already signed" << std::endl;
		return ;
	}
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade <= this->_gradeSign)
	{
		this->_signed = true;
		object.signForm(*this);
	}
	else
	{
		object.signForm(*this);
		throw Form::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
    out << "Form: " << obj.getName()
		<< ", signed: " << std::boolalpha << obj.getSigned()
		<< ", Grade to Sign: "<< obj.getGradeSign()
		<< ", Grade to Execute: " << obj.getGradeExec() << std::endl;
    return out;
}