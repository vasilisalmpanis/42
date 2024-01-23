#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj.getName(), obj.getGradeSign(), obj.getGradeExec()), _target(obj.getTarget()) {
    *this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this != &obj)
    {
        this->_target = obj._target;
        this->setSigned(obj.getSigned());
    }
    return *this;
}

// Getters

std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

//Public

int RobotomyRequestForm::nameToNumber() const {
    int total = 0;
    std::string name = this->getName();
    for (std::size_t i = 0; i < name.length(); ++i) {
        total += static_cast<int>(name[i]);
    }
    return total;
}

int RobotomyRequestForm::_rand() const
{
	unsigned long a = clock();
	unsigned long b = time(NULL);
	unsigned long c = this->nameToNumber();
	a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
	std::srand(c);
	return std::rand();
}

void RobotomyRequestForm::action() const
{
    int randomNumber = this->_rand();
    if (randomNumber % 2 == 0)
        std::cout << this->_target << " has been robotomized succesfully" << std::endl;
    else
        std::cout << this->_target << " could not be robotomized" << std::endl;
}