#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(char* argv[], int argc);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	private:
		void split();
		void debug();

		std::vector<int> buff;
		std::vector< std::vector<int> > pairs;
		std::list<int> list;
		bool hasStragler;
		int stragler;
		int count;
};
