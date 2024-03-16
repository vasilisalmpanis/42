#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <cmath>
#include <ctime>

class PmergeMe
{
	public:

		void mergeInsertionVector();
		void mergeInsertionDeque();

		PmergeMe();
		PmergeMe(char* argv[], int argc);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	private:
		void split(std::vector<int> &buff, std::deque<int> &buffD);
		void sortEachPairV();
		void sortByHigherValueV();
		void insertionSortV(int length);
		void insertV(std::vector<int> pair, int length);
		void createSortedListV();
		void binaryInsertV(int value, int max);

		void sortEachPairD();
		void sortByHigherValueD();
		void insertionSortD(int length);
		void insertD(std::deque<int> pair, int length);
		void createSortedListD();
		void binaryInsertD(int value, int max);

		std::vector< std::vector<int> > pairs;
		std::vector<int> sortedList;

		std::deque< std::deque<int> > pairsD;
		std::deque<int> sortedListD;

		bool hasStragler;
		int stragler;
		int count;
};

void printVector(std::vector<int> &v, std::string prefix);
void printDeque(std::deque<int> &vec, std::string message);
int jacobsthal(int n);
bool isNumber(const char* str);