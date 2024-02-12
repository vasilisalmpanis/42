#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &rhs);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
	private:
		void addRate(std::string date, double rate);
		void populateRates(std::fstream &file);
		std::map<std::string, double> exchangeRates;
};

bool isDateValidFormat(std::string Date);
bool isDateValid(std::string date);
bool isLeapYear(int year, int day);


