#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {

    // ShrubberyCreationForm
    {
        ShrubberyCreationForm ShrubbForm("Schrubb Form");
        Bureaucrat BureaucratCanSign("I can sign", 130);
        Bureaucrat BureaucratCantSign("I cant sign", 146);
        try
        {
            ShrubbForm.beSigned(BureaucratCantSign); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            ShrubbForm.beSigned(BureaucratCanSign); // No Exception
            BureaucratCanSign.executeForm(ShrubbForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Presidential
    std::cout << std::endl;

    {
        PresidentialPardonForm PresidentForm("President Form");
        Bureaucrat BureaucratCanSign("I can sign", 4);
        Bureaucrat BureaucratCantSign("I cant sign", 26);
        try
        {
            PresidentForm.beSigned(BureaucratCantSign); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            PresidentForm.beSigned(BureaucratCanSign); // No Exception
            BureaucratCanSign.executeForm(PresidentForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Robotomy
    std::cout << std::endl;

    {
        RobotomyRequestForm RobotForm("Robotomy Form");
        Bureaucrat BureaucratCanSign("I can sign", 44);
        Bureaucrat BureaucratCantSign("I cant sign", 73);
        try
        {
            RobotForm.beSigned(BureaucratCantSign); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            RobotForm.beSigned(BureaucratCanSign); // No Exception
            BureaucratCanSign.executeForm(RobotForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("hello", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}