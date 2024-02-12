#include "BitcoinExchange.hpp"
#include <fstream>
#include <limits>
#include <sstream>

void trim(std::string &val)
{
	if (!val.size())
		return ;
	size_t	pos = 0;
	while (pos < val.size() && std::isspace(val[pos]))
		pos++;
	if (pos > 0)
		val.erase(0, pos);
	pos = 0;
	while (val.size() > 0 && std::isspace(val[val.size() - 1]))
		val.erase(val.size() - 1, 1);
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
	std::fstream file("database.csv", std::ios::in);
	if (!file.is_open() && !file.good())
		throw std::runtime_error("File could not be opened");
	populateRates(file);
	file.close();
	std::fstream inputFile(fileName, std::ios::in);
	if (!inputFile.is_open() && !inputFile.good())
		throw std::runtime_error("Input File could not be opened");
	splitResults(inputFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
	exchangeRates = rhs.exchangeRates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		exchangeRates = rhs.exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// Destructor
}

// Private member functions

void BitcoinExchange::calculateBitcoin(std::string date, double amount)
{
	double rate;
	std::map<std::string, double>::iterator pos;
	
	pos = exchangeRates.find(date);
	if (pos == exchangeRates.end())
	{
		pos = exchangeRates.lower_bound(date);
		if (pos == exchangeRates.end())
		{
			std::cout << "No data available for " << date << std::endl;
			return ;
		}
		if (pos != exchangeRates.begin())
			pos--;
		rate = pos->second;
		std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
		return ;
	}
	std::cout << date << " => " << amount << " = " << amount * pos->second << std::endl;
}

void BitcoinExchange::printResults(std::string line)
{
	if (line.empty())
		return ;
	std::string date;
	std::string value;
	size_t pos;
	double amount;

	pos = line.find('|');
	if (pos == std::string::npos)
	{
		std::cout << "Error: Bad Input: => " << line << std::endl;
		return ;
	}
	date = line.substr(0, pos);
	trim(date);
	if (!isDateValidFormat(date) || !isDateValid(date))
	{
		std::cout << "Error: Bad Date Format: => " << date << std::endl;
		return ;
	}
	value = line.substr(pos + 1);
	trim(value);
	amount = stringToDouble(value);
	if (amount < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return ;
	}
	else if (std::numeric_limits<int>::max() < amount)
	{
		std::cout << "Error: too large a number" << std::endl;
		return ;
	}
	calculateBitcoin(date, amount);
}

void BitcoinExchange::splitResults(std::fstream &file)
{
	std::string line;
	std::stringstream ss;
	ss << file.rdbuf();
	std::getline(ss, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid input file format " + line);
	while (std::getline(ss, line))
		printResults(line);
}

void BitcoinExchange::populateRates(std::fstream &file)
{
	std::string line;
	std::string date;
	std::string rateString;
	char *end;
	size_t pos;
	double rate;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid file format");
	while (std::getline(file, line))
	{
		if (line == "")
			continue ;
		date.clear();
		rate = 0;
		std::stringstream ss(line);
		pos = line.find(',');
		if (pos == std::string::npos || pos < 10)
			throw std::runtime_error("Invalid file format");
		date = line.substr(0, line.find(','));
		trim(date);
		rateString = line.substr(pos + 1);
		trim(rateString);
		rate = strtod(rateString.c_str(), &end);
		addRate(date, rate);
	}
}

void BitcoinExchange::addRate(std::string date, double rate)
{
	if (exchangeRates.find(date) != exchangeRates.end())
		throw std::runtime_error("Date already exists");
	if (!isDateValidFormat(date))
		throw std::runtime_error("Date is not in the correct format" + date);
	if (!isDateValid(date))
		throw std::runtime_error("Date is not valid");
	if (rate < 0)
		throw std::runtime_error("Rate is negative");
	exchangeRates[date] = rate;
}
