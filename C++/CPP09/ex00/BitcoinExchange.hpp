#pragma once
#include <iostream>
#include <string>
#include <vector>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoindExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &rhs);
		~BitcoinExchange();
		Bitcoin &operator=(const BitcoinExchange &rhs);
};

bool isValidDate(std::string date);

