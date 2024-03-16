#include "PmergeMe.hpp"

#include <ctime>

#include <iostream>
#include <ctime> // Include the ctime library

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " [integers...]" << std::endl;
		return 1;
	}
	try 
	{
		PmergeMe pmergeMe(argv, argc);

		clock_t startV = clock();
		pmergeMe.mergeInsertionVector();
		clock_t endV = clock();
		double duration = static_cast<double>(endV - startV) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time taken to process a range of " << argc - 1 << " with std::vector: " << duration << " microseconds" << std::endl;
		clock_t startD = clock();
		pmergeMe.mergeInsertionDeque();
		clock_t endD = clock();
		duration = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time taken to process a range of " << argc - 1 << " with std::deque: " << duration << " microseconds" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
