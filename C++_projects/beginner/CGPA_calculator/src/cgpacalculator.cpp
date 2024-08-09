#include "cgpacalculator.hpp"
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <string>

inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from left & right
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

CGPACalculator::CGPACalculator(void) : credit_hours(0), quality_points(0), average(0)
{}

CGPACalculator::~CGPACalculator(void)
{}

void CGPACalculator::parse(void)
{
	//read from stdin till EOF
	// prompt for credit and quality score seperated by space
	// if prompt is empty or just whitespace evaluate average;
	std::string line;
	std::string credit;
	std::string quality;
	std::cout << "Please write your quality points and credit hours separated by space" << std::endl; 
	while(std::getline(std::cin, line)) {
		trim(line);
		if (line.size() == 0)
			break;
		if (line.find_first_of(" \t") == std::string::npos)
			std::cout << "Invalid entry" << std::endl;
		std::stringstream ss;
		ss << line;
		ss >> quality;
		ss >> credit;
		try {
			float cre = std::stof(credit);	
			float qua = std::stof(quality);	
			this->credit_hours += cre;
			this->quality_points += qua;
		}
		catch (...) {
			continue;
		}
	}
	if (this->credit_hours == 0)
		return;
	this->average = this->quality_points / this->credit_hours;
	std::cout << "CGPA: " << average << std::endl;
}
