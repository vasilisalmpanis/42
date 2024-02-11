#include "BitcoinExchange.hpp"
#include <tuple>

bool isValidDate(std::string Date){
	// Check if the date is in the correct format
	// The date should be in the format "YYYY-MM-DD"
	// The date should be a valid date
	if (Date.length() != 10){
		return false;
	}
	if (Date[4] != '-' || Date[7] != '-'){
		return false;
	}
	std::string year = Date.substr(0, 4);
	std::string month = Date.substr(5, 2);
	std::string day = Date.substr(8, 2);

	if (!std::all_of(year.begin(), year.end(), [](char c) { return std::isdigit(c); }))
		return false;
	if (!std::all_of(month.begin(), month.end(), [](char c) { return std::isdigit(c); }) || month > "12" || month < "01")
		return false;
	if (!std::all_of(day.begin(), day.end(), [](char c) { return std::isdigit(c); }) || day > "31" || day < "01")
		return false;
	return true;
}


