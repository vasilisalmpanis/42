#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

class ScalarConverter
{
		
	static	bool	isPrintable(std::string &);
	static	bool	isChar(std::string &);
	static	bool	isInt(std::string &);
	static	bool	isFloat(std::string &);
	static	bool	isDouble(std::string &);
	static	bool	isPseudoLiteral(std::string &);
	static void	printChar(std::string str);
	static void	printInt(std::string str);
	static void	printFloat(std::string str);
	static void	printDouble(std::string str);
	static void	printPseudoLiteral(std::string str);
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		virtual ScalarConverter & operator=(ScalarConverter const &) = 0;
		virtual ~ScalarConverter();

		// Public methods
		static void convert(std::string str);
};
