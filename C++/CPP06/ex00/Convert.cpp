#include "ScalarConverter.hpp"
// Check if the string is a printable character
// A printable character is defined as:
// 1. A single character
// 2. A character between 32 and 126 (inclusive)
// 3. A character that is not a digit
bool	isPrintable(std::string &input) {
	if (input.length() == 1 && input[0] >= 32 && input[0] <= 126)
		return true;
	return false;
}

// Checks if the string is a character other than a digit
bool	isChar(std::string &input) {
	if (input.length() > 1)
		return false;
	if (std::isdigit(input[0]) || !::isPrintable(input))
		return false;
	return true;
}

// Checks if the string is an integer
bool	isInt(std::string &input) {
    if (input.empty())
        return false;
    size_t start_index = 0;
    if (input[0] == '-') {
        // If the string contains only the negative sign, it's not a valid integer
        if (input.size() == 1)
            return false;
        start_index = 1;  // Skip the negative sign
    }
    for (size_t i = start_index; i < input.size(); ++i) {
        // Check if the character is a digit
        if (!std::isdigit(input[i])) {
            return false;
        }
    }
    long long int value = std::atoll(input.c_str());
    // Check if the value is within the range of an integer
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	return false;
    return true;
}

// Checks if the string is a float
// A float is defined as:
// 1. An optional sign character (+ or -)
// 2. One or more digits, followed by a decimal point
// 3. Zero or more digits after the decimal point
// 4. An f or F character at the endl
bool isFloat(std::string &input) {
	size_t startIndex = 0;
	int dotCount = 0;
	int fCount = 0;
	if (input.length() < 3 || input[input.size() - 1] != 'f')
		return false;
	if (input[0] == '+' || input[0] == '-')
		startIndex = 1;
	for (size_t i = startIndex; i < input.length(); i++)
	{
		if (input[i] == '.')
			dotCount++;
		else if (input[i] == 'f')
			fCount++;
		else if (!std::isdigit(input[i]))
			return false;
	}
	if (dotCount != 1 || fCount != 1)
		return false;
	return true;
}

// Checks if the string is a double
// A double is defined as:
// 1. An optional sign character (+ or -)
// 2. One or more digits, followed by a decimal point
// 3. Zero or more digits after the decimal point
bool isDouble(std::string &input) {
	size_t startIndex = 0;
	int dotCount = 0;
	if (input[0] == '+' || input[0] == '-')
		startIndex = 1;
	for (size_t i = startIndex; i < input.length(); i++)
	{
		if (input[i] == '.')
			dotCount++;
		else if (!std::isdigit(input[i]))
			return false;
	}
	if (dotCount != 1)
		return false;
	return true;
}

// Checks if the string is a pseudo-literal
// A pseudo-literal is defined as:
// 1. -inff
// 2. +inff
// 3. nanf
// 4. -inf
// 5. +inf
// 6. nan
bool isPseudoLiteral(std::string &input) {
	if (input == "-inff" 
			|| input == "+inff" 
			|| input == "nanf" 
			|| input == "-inf" 
			|| input == "+inf" 
			|| input == "nan")
		return true;
	return false;
}


// Prints the char value of the string
void printChar(std::string str)
{
	char c = str[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// Prints the int value of the string
void printInt(std::string str)
{
	int i = std::atoi(str.c_str());
	std::cout << "char: ";
	if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void printFloat(std::string str)
{
	float	numInFloat = std::atof(str.c_str());
	char	numInChar = static_cast<char>(numInFloat);
	int	numInInt = static_cast<int>(numInFloat);
	double	numInDouble = static_cast<double>(numInFloat);
	std::cout << "char: ";
	if (numInDouble < 32.0 || numInDouble > 126.0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << numInChar << "'" << std::endl;
	std::cout << "int: ";
	if (numInDouble > std::numeric_limits<int>::max() || numInDouble < std::numeric_limits<int>::min())
			std::cout << "Impossible" << std::endl;
	else
	 		std::cout << numInInt << std::endl;
	if (fmod(numInDouble, 1.0) == 0 && str.find(".") <= 5) {
		std::cout << "float: " << numInFloat << ".0f" << std::endl;
		std::cout << "double: " << numInDouble << ".0" <<std::endl;
	}
	else {

		std::cout << "float: " << numInFloat << "f" << std::endl;
		std::cout << "double: " << numInDouble  <<std::endl;
	}
}

void printDouble(std::string str)
{
	char*	endPtr;
	double	numInDouble = strtod(str.c_str(), &endPtr );
	float	numInFloat = static_cast<float>(numInDouble);
	char	numInChar = static_cast<char>(numInDouble);
	int	numInInt = static_cast<int>(numInDouble);
	std::cout << "char: ";
	if (numInDouble < 32.0 || numInDouble > 126.0)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << numInChar << "'" << std::endl;
	std::cout << "int: ";
	if (numInDouble > std::numeric_limits<int>::max() || numInDouble < std::numeric_limits<int>::min())
			std::cout << "Impossible" << std::endl;
	else
	 		std::cout << numInInt << std::endl;
	if (fmod(numInDouble, 1.0) == 0 && str.find(".") <= 5) {
		if (numInDouble > std::numeric_limits<float>::max() || numInDouble < std::numeric_limits<float>::min())
			std::cout << "float: Impossible" << std::endl;
		else
			std::cout << "float: " << numInFloat << ".0f" << std::endl;
		std::cout << "double: " << numInDouble << ".0" <<std::endl;
	}
	else {
		if (numInDouble > std::numeric_limits<float>::max() || numInDouble < std::numeric_limits<float>::min())
			std::cout << "float: Impossible" << std::endl;
		else
			std::cout << "float: " << numInFloat << "f" << std::endl;
		std::cout << "double: " << numInDouble  <<std::endl;
	}
}

void printPseudoLiteral(std::string str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		str += "f";
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}