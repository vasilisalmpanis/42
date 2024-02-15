#include "PmergeMe.hpp"
#include <stdexcept>

PmergeMeVector::PmergeMeVector() : hasStragler(false), stragler(0), count(0), comparisons(0)
{
}

bool isNumber(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

PmergeMeVector::PmergeMeVector(char* argv[], int argc) : hasStragler(false), stragler(0), count(argc - 1), comparisons(0)
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		if (!isNumber(argv[i]))
			throw std::runtime_error("Invalid input");
		buff.push_back(std::atoi(argv[i]));
	}
	std::cout << "Before: ";
	for (int i = 1; argv[i] != NULL; i++)
	{
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	if (count % 2)
	{
		this->hasStragler = true;
		this->stragler = buff[count - 1];
		this->count--;
	}
	this->split();
	this->sortEachPair();
	this->sortByHigherValue();
	this->createSortedList();

}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& other)
{
	*this = other;
}

PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& other)
{
	if (this != &other)
	{
		this->buff = other.buff;
		this->list = other.list;
		this->pairs = other.pairs;
		this->hasStragler = other.hasStragler;
		this->stragler = other.stragler;
		this->count = other.count;
		this->comparisons = other.comparisons;
		this->sortedList = other.sortedList;
	}
	return *this;
}

PmergeMeVector::~PmergeMeVector()
{
}

// Private methods

void PmergeMeVector::binaryInsert(int value, int index)
{
	if (index > static_cast<int>(sortedList.size()))
		index = sortedList.size();
	std::vector<int>::iterator it = std::lower_bound(sortedList.begin(), sortedList.begin() + index, value);

	if (it == sortedList.end())
		sortedList.push_back(value);
	else
		sortedList.insert(it, value);
}

int jacobsthal(int n)
{
    return (std::pow(2, n + 1) + std::pow(-1, n)) / 3;
}

void PmergeMeVector::createSortedList()
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
			this->binaryInsert(pend[i], pairs[i][1]);
			--i;
		}
		i += distance_forward;
		++jacobs_index;
	}
	std::cout << std::endl;
	const size_t start = i;

	i = pend.size() - 1;
	while (i > start)
	{
		this->binaryInsert(pend[i], pairs[i][1]);
		--i;
	}
	std::cout << "After: ";
	for (std::vector<int>::iterator it = sortedList.begin(); it != sortedList.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMeVector::insert(std::vector<int> pair , int length)
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
		insert(pair, length - 1);
	}
}

void PmergeMeVector::insertionSort(int length)
{
	if (length < 1)
		return;
	insertionSort(length - 1);
	insert(pairs[length], length - 1);
}

void PmergeMeVector::sortByHigherValue()
{
	// length of sorte pair array
	int length = pairs.size();
	insertionSort(length - 1);
}

void PmergeMeVector::sortEachPair()
{
	for (std::vector< std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->at(0) > it->at(1))
		{
			int temp = it->at(0);
			it->at(0) = it->at(1);
			it->at(1) = temp;
		}
		comparisons++;
	}
}
void PmergeMeVector::split()
{
	for (int i = 0; i < count; i += 2)
	{
		std::vector<int> pair;
		pair.push_back(buff[i]);
		pair.push_back(buff[i + 1]);
		pairs.push_back(pair);
	}
	this->buff.clear();
}

void PmergeMeVector::debug()
{
	std::cout << "Pairs: " << std::endl;
	for (std::vector< std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << it->at(0) << " " << it->at(1) << std::endl;
	}
	std::cout << "Stragler: " << stragler << std::endl;
}
