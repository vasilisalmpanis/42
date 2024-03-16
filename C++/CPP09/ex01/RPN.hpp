#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

class RPN {
	public:
		RPN();
		RPN(std::string);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();
	private:
		std::stack<long long int> stack;
		void add();
		void subtract();
		void multiply();
		void divide();
		void checkExpression(std::string);
};
