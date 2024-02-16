#include "PmergeMe.hpp"
#include <stdexcept>

PmergeMe::PmergeMe() : hasStragler(false), stragler(0), count(0)
{
}

PmergeMe::PmergeMe(char* argv[], int argc) : hasStragler(false), stragler(0), count(argc - 1)
{
	std::vector<int> buff;
	std::deque<int> buffD;
	for (int i = 1; argv[i] != NULL; i++)
	{
		if (!isNumber(argv[i]))
			throw std::runtime_error("Invalid input");
		buff.push_back(std::atoi(argv[i]));
		buffD.push_back(std::atoi(argv[i]));
	}
	printVector(buff, "Before: ");
	if (count % 2)
	{
		this->hasStragler = true;
		this->stragler = buff[count - 1];
		this->count--;
	}
	this->split(buff, buffD);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->pairs = other.pairs;
		this->hasStragler = other.hasStragler;
		this->stragler = other.stragler;
		this->count = other.count;
		this->sortedList = other.sortedList;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::mergeInsertionVector()
{
	this->sortEachPairV();
	this->sortByHigherValueV();
	this->createSortedListV();
}

void PmergeMe::mergeInsertionDeque()
{
	this->sortEachPairD();
	this->sortByHigherValueD();
	this->createSortedListD();
}

// Private methods


// Deque methods

void PmergeMe::binaryInsertD(int value, int index)
{
	if (index > static_cast<int>(sortedListD.size()))
		index = sortedListD.size();
	std::deque<int>::iterator it = std::lower_bound(sortedListD.begin(), sortedListD.begin() + index, value);

	if (it == sortedListD.end())
		sortedListD.push_back(value);
	else
		sortedListD.insert(it, value);
}

void PmergeMe::createSortedListD()
{
	std::deque<int> pend;
	size_t end = pairsD.size();
	for(size_t i = 0; i < end; i++)
	{
		sortedListD.push_back(pairsD[i][1]);
		pend.push_back(pairsD[i][0]);
	}
	sortedListD.insert(sortedListD.begin(), pend[0]);

	size_t i = 0;
	size_t jacobs_index = 1;
	while (true)
	{
		const int distance_forward = 2 * jacobsthal(jacobs_index);
		if (i + distance_forward >= pend.size()) break;

		const size_t start = i;
		i += distance_forward;
		while (i > start)
		{
			this->binaryInsertD(pend[i], pairsD[i][1]);
			--i;
		}
		i += distance_forward;
		++jacobs_index;
	}
	const size_t start = i;
	i = pend.size() - 1;
	while (i > start)
	{
		this->binaryInsertD(pend[i], pairsD[i][1]);
		--i;
	}
	if (hasStragler)
		this->binaryInsertD(stragler, sortedList.size());
}

void PmergeMe::insertD(std::deque<int> pair , int length)
{
	if (length < 0)
	{
		pairsD[0] = pair;
		return;
	}
	if (pair[1] >= pairs[length][1])
			pairsD[length + 1] = pair;
	else
	{
		pairsD[length + 1] = pairsD[length];
		insertD(pair, length - 1);
	}
}

void PmergeMe::insertionSortD(int length)
{
	if (length < 1)
		return;
	insertionSortD(length - 1);
	insertD(pairsD[length], length - 1);
}

void PmergeMe::sortByHigherValueD()
{
	// length of sorte pair array
	int length = pairsD.size();
	insertionSortD(length - 1);
}

void PmergeMe::sortEachPairD()
{
	for (std::deque< std::deque<int> >::iterator it = pairsD.begin(); it != pairsD.end(); it++)
	{
		if (it->at(0) > it->at(1))
		{
			int temp = it->at(0);
			it->at(0) = it->at(1);
			it->at(1) = temp;
		}
	}
}


// Vector methods

void PmergeMe::binaryInsertV(int value, int index)
{
	if (index > static_cast<int>(sortedList.size()))
		index = sortedList.size();
	std::vector<int>::iterator it = std::lower_bound(sortedList.begin(), sortedList.begin() + index, value);

	if (it == sortedList.end())
		sortedList.push_back(value);
	else
		sortedList.insert(it, value);
}

void PmergeMe::createSortedListV()
{
	std::vector<int> pend;
	size_t end = pairs.size();
	for(size_t i = 0; i < end; i++)
	{
		sortedList.push_back(pairs[i][1]);
		pend.push_back(pairs[i][0]);
	}
	sortedList.insert(sortedList.begin(), pend[0]);

	size_t i = 0;
	size_t jacobs_index = 1;
	while (true)
	{
		const int distance_forward = 2 * jacobsthal(jacobs_index);
		if (i + distance_forward >= pend.size()) break;

		const size_t start = i;
		i += distance_forward;
		while (i > start)
		{
			this->binaryInsertV(pend[i], pairs[i][1]);
			--i;
		}
		i += distance_forward;
		++jacobs_index;
	}
	const size_t start = i;
	i = pend.size() - 1;
	while (i > start)
	{
		this->binaryInsertV(pend[i], pairs[i][1]);
		--i;
	}
	if (hasStragler)
		this->binaryInsertV(stragler, sortedList.size());
	printVector(sortedList, "After:  ");
}

void PmergeMe::insertV(std::vector<int> pair , int length)
{
	if (length < 0)
	{
		pairs[0] = pair;
		return;
	}
	if (pair[1] >= pairs[length][1])
			pairs[length + 1] = pair;
	else
	{
		pairs[length + 1] = pairs[length];
		insertV(pair, length - 1);
	}
}

void PmergeMe::insertionSortV(int length)
{
	if (length < 1)
		return;
	insertionSortV(length - 1);
	insertV(pairs[length], length - 1);
}

void PmergeMe::sortByHigherValueV()
{
	// length of sorte pair array
	int length = pairs.size();
	insertionSortV(length - 1);
}

void PmergeMe::sortEachPairV()
{
	for (std::vector< std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->at(0) > it->at(1))
		{
			int temp = it->at(0);
			it->at(0) = it->at(1);
			it->at(1) = temp;
		}
	}
}

void PmergeMe::split(std::vector<int> &buff, std::deque<int> &buffD)
{
	for (int i = 0; i < count; i += 2)
	{
		std::vector<int> pair;
		pair.push_back(buff[i]);
		pair.push_back(buff[i + 1]);
		pairs.push_back(pair);

		std::deque<int> pairD;
		pairD.push_back(buffD[i]);
		pairD.push_back(buffD[i + 1]);
		pairsD.push_back(pairD);
	}
	buff.clear();
	buffD.clear();
}


// Helper

int jacobsthal(int n)
{
    return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}

void printVector(std::vector<int> &vec, std::string message)
{
	std::cout << message;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void printDeque(std::deque<int> &vec, std::string message)
{
	std::cout << message;
	for (std::deque<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool isNumber(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
			throw std::runtime_error("Error");
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}