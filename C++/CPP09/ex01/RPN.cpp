#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <string>

RPN::RPN() {
}

RPN::RPN(std::string expression) {
	checkExpression(expression);
}

RPN::RPN(const RPN& rpn) {
	stack = rpn.stack;
}

RPN& RPN::operator=(const RPN& rpn) {
	if (this != &rpn) {
		stack = rpn.stack;
	}
	return *this;
}

RPN::~RPN() {
}

// Private member functions
//
bool isOperator(std::string token)
{
	const std::string operators[] = {"+", "-", "*", "/"};
	for (int i = 0; i < 4; i++)
	{
		if (token == operators[i])
			return true;
	}
	return false;
}

void RPN::checkExpression(std::string expression) {
	std::string token;
	std::stringstream ss;
	ss << expression;
	const std::string operators[] = {"+", "-", "*", "/"};
	void (RPN::*operations[])() = { &RPN::add,
					&RPN::subtract, 
					&RPN::multiply, 
					&RPN::divide
					};

	while(std::getline(ss, token, ' '))
	{
		if (token.length() != 1)
			throw std::runtime_error("Invalid token length: " + token);
		if (!std::isdigit(token[0]) && !isOperator(token))
			throw std::runtime_error("Invalid token char: " + token);
		if (std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else
		{
			if (stack.size() < 2)
				throw std::runtime_error("Invalid expression: " + expression);
			for (size_t i = 0; i < 4; i++)
			{
				if (token == operators[i])
				{
					(this->*operations[i])();
					break;
				}
			}
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression: " + expression);
	std::cout << stack.top() << std::endl;
}


void RPN::add() {
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(a + b);
}

void RPN::subtract() {
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(b - a);
}


void RPN::multiply() {
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	stack.push(a * b);
}

void RPN::divide() {
	int a = stack.top();
	stack.pop();
	int b = stack.top();
	stack.pop();
	if (a == 0)
		throw std::runtime_error("Division by zero");
	stack.push(b / a);
}

