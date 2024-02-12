#include "BitcoinExchange.hpp"

bool all_digits(std::string::iterator start, std::string::iterator end)
{
	while (start != end)
	{
		if (!std::isdigit(*start))
			return false;
		++start;
	}
	return true;
}

double stringToDouble(std::string num)
{
	char *end;
	double value = strtod(num.c_str(), &end);
	return value;
}

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

	if (!all_digits(year.begin(), year.end()) || year < "2009" || year > "2024")
		return false;
	if (!all_digits(month.begin(), month.end()) || month > "12" || month < "01")
		return false;
	if (!all_digits(day.begin(), day.end()) || day > "31" || day < "01")
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
