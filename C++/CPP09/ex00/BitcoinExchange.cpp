#include "BitcoinExchange.hpp"

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
	for (auto &i : exchangeRates)
		std::cout << i.first << " " << i.second << std::endl;
	(void)fileName;
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


void BitcoinExchange::populateRates(std::fstream &file)
{
	std::string line;
	std::string date;
	std::string rateString;
	char *end;
	size_t pos;
	double rate;
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
