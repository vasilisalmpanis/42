#include "cgpacalculator.hpp"

void help(void)
{
	std::cout << "Usage: CGPACalculator" << std::endl;
	std::cout << "The program will prompt you for grades to be evaluated" << std::endl;
}

// TODO pass options to parse from a file

int main(int argc, char **argv)
{
	if (argc != 1) {
		help();
		return 1;
	}
	CGPACalculator calc;
	calc.parse();
}
