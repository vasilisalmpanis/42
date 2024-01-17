#include "AForm.hpp"

AForm::AForm(): _name("empty"), _signed(false), _gradeSign(150), _gradeExec(150) {
	
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{

}

AForm::AForm(const AForm &other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

// Getters

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getGradeSign() const 
{
	return this->_gradeSign;
}

int AForm::getGradeExec() const
{
	return this->_gradeExec;
}

// Exceptions

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Form Grade Too Low");
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Form Grade Too High");
}

const char *AForm::FormNotSigned::what() const throw() {
    return ("Form is not signed");
}

// Setters

void AForm::setSigned(bool value)
{
	this->_signed = value;
}

// Public

void AForm::beSigned(Bureaucrat &object)
{
	int grade = object.getGrade();

	if (this->_signed)
	{
		std::cout << "AForm " << this->_name << " is already signed" << std::endl;
		return ;
	}
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade <= this->_gradeSign)
	{
		this->_signed = true;
		object.signForm(*this);
	}
	else
	{
		object.signForm(*this);
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	else if (!this->_signed)
		throw AForm::FormNotSigned();
	action();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
    out << "AForm: " << obj.getName()
		<< ", signed: " << std::boolalpha << obj.getSigned()
		<< ", Grade to Sign: "<< obj.getGradeSign()
		<< ", Grade to Execute: " << obj.getGradeExec() << std::endl;
    return out;
}