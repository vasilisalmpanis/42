#include "PmergeMe.hpp"
#include <stdexcept>

PmergeMe::PmergeMe() : hasStragler(false), stragler(0), count(0)
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

PmergeMe::PmergeMe(char* argv[], int argc) : hasStragler(false), stragler(0), count(argc - 1)
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		if (!isNumber(argv[i]))
			throw std::runtime_error("Invalid input");
		buff.push_back(std::atoi(argv[i]));
	}
	if (count % 2)
	{
		this->hasStragler = true;
		this->stragler = buff[count - 1];
		this->count--;
	}
	this->split();
	this->debug();
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->buff = other.buff;
		this->list = other.list;
		this->pairs = other.pairs;
		this->hasStragler = other.hasStragler;
		this->stragler = other.stragler;
		this->count = other.count;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::split()
{
	for (int i = 0; i < count; i += 2)
	{
		std::vector<int> pair;
		pair.push_back(buff[i]);
		pair.push_back(buff[i + 1]);
		pairs.push_back(pair);
	}
}

void PmergeMe::debug()
{
	std::cout << "Pairs: " << std::endl;
	for (std::vector< std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::cout << it->at(0) << " " << it->at(1) << std::endl;
	}
	std::cout << "Stragler: " << stragler << std::endl;
}
