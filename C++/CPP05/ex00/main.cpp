#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat highGradeBureaucrat("John", 5);
        std::cout << highGradeBureaucrat << std::endl;
        highGradeBureaucrat.incrementGrade();
        std::cout << "After incrementing: " << highGradeBureaucrat << std::endl;
        highGradeBureaucrat.decrementGrade();
        std::cout << "After decrementing: " << highGradeBureaucrat << std::endl;

        Bureaucrat invalidHighGrade("InvalidHigh", 0);  // This should throw an exception

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidLowGrade("InvalidLow", 151);  // This should throw an exception

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}