#include "Intern.hpp"

// Private

AForm *Intern::makeShrubbForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRoboForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

// Public

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target)
{
    const std::string FormTypes[3] = {
        "shrubbery request",
        "robotomy request",
        "presidential request"
    };
    AForm *(Intern::*collection[3])(const std::string) = {
        &Intern::makeShrubbForm,
        &Intern::makeRoboForm,
        &Intern::makePresidentForm,
    };
    for (int i = 0; i < 3; i++)
    {
        if (name == FormTypes[i])
            return (this->*collection[i])(target);
    }
    std::cout << "Form could not be made" << std::endl;
    throw Intern::FormTypeDoesntExist();
}

// Exception

const char *Intern::FormTypeDoesntExist::what() const throw() {
    return ("Form type is invalid");
}