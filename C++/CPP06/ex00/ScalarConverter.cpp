#include "ScalarConverter.hpp"
#include <cstddef>
#include <limits>
#include <math.h>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}


// Public methods


// Converts the string to a char, int, float, and double
// and prints the results
void ScalarConverter::convert(std::string str) {
	if (isChar(str))
		printChar(str);
	else if (isInt(str))
		printInt(str);
	else if (isFloat(str))
		printFloat(str);
	else if (isDouble(str))
		printDouble(str);
	else if (isPseudoLiteral(str))
		printPseudoLiteral(str);
	else
		std::cout << "Error: invalid input" << std::endl;
}
