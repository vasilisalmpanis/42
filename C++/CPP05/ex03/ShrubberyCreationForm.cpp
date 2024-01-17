#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExec()), _target(obj.getTarget()) {
    *this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this != &obj)
    {
        this->_target = obj._target;
        this->setSigned(obj.getSigned());
    }
    return *this;
}

// Getters

std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

//Public

void ShrubberyCreationForm::action() const
{
    std::string filename = this->_target + "_shrubbery";
    std::ofstream fileToExecuteAction;
    fileToExecuteAction.open(filename.c_str(), std::ios::out | std::ios::app);
    if (fileToExecuteAction.is_open())
    {
        fileToExecuteAction << "    ^^^\n";
        fileToExecuteAction << "   ^^^^\n";
        fileToExecuteAction << "  ^^^^^\n";
        fileToExecuteAction << " ^^^^^^\n";
        fileToExecuteAction << "^^^^^^^\n";
        fileToExecuteAction << "   ||| \n";
        fileToExecuteAction.close();
    }
}