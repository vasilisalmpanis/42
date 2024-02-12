#include "BitcoinExchange.hpp"

bool isDateValidFormat(std::string Date){
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


bool isDateValid(std::string Date)
{
	int year, month, day;
	year = std::atoi(Date.substr(0, 4).c_str());
	month = std::atoi(Date.substr(5, 2).c_str());
	day = std::atoi(Date.substr(8, 2).c_str());
	if (year < 2009 || year > 2024) 
		return false;
	if (month == 1 ||
		month == 3 ||
		month == 5 ||
		month == 7 ||
		month == 8 ||
		month == 10 ||
		month == 12)
	{
		if (day < 1 || day > 31)
			return false;
	}
	else if (month == 2)
		return isLeapYear(year, day);
	else if (day > 30)
		return false;
	return true;
}

bool isLeapYear(int year, int day)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		if (day < 1 || day > 29)
			return false;
	}
	else
	{
		if (day < 1 || day > 28)
			return false;
	}
	return true;
}
