#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>
#include <math.h>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		virtual ScalarConverter & operator=(ScalarConverter const &) = 0;
		virtual ~ScalarConverter();

		// Public methods
		static void convert(std::string str);
};

bool	isPrintable(std::string &);
bool	isChar(std::string &);
bool	isInt(std::string &);
bool	isFloat(std::string &);
bool	isDouble(std::string &);
bool	isPseudoLiteral(std::string &);
void	printChar(std::string str);
void	printInt(std::string str);
void	printFloat(std::string str);
void	printDouble(std::string str);
void	printPseudoLiteral(std::string str);