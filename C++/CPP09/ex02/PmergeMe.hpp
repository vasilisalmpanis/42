#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>	

class PmergeMeVector
{
	public:
		PmergeMeVector();
		PmergeMeVector(char* argv[], int argc);
		PmergeMeVector(const PmergeMeVector& other);
		PmergeMeVector& operator=(const PmergeMeVector& other);
		~PmergeMeVector();
	private:
		void split();
		void sortEachPair();
		void sortByHigherValue();
		void insertionSort(int length);
		void insert(std::vector<int> pair, int length);
		void createSortedList();
		void binaryInsert(int value, int max);
		void debug();

		std::vector<int> buff;
		std::vector< std::vector<int> > pairs;
		std::vector<int> sortedList;
		std::list<int> list;
		bool hasStragler;
		int stragler;
		int count;
		int comparisons;
};
