/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:49:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/12 12:49:10 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Constructor Called." << std::endl;
	index = 0;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destructor Called." << std::endl;
}
//
//void PhoneBook::setFirstName(std::string string, int i)
//{
//	firstName[i] = string;
//}
//std::string PhoneBook::setFirstName(int i)
//{
//	return (firstName[i]);
//}
//
//void PhoneBook::setLastName(std::string string, int i)
//{
//	lastName[i] = string;
//}
//std::string PhoneBook::setLastName(int i)
//{
//	return (lastName[i]);
//}
//void PhoneBook::setNickname(std::string string, int i)
//{
//	nickname[i] = string;
//}
//std::string PhoneBook::setNickname(int i)
//{
//	return (nickname[i]);
//}
//
//void PhoneBook::setPhoneNumber(std::string string, int i)
//{
//	phoneNumber[i] = string;
//}
//std::string PhoneBook::getPhoneNumber(int i)
//{
//	return (phoneNumber[i]);
//}
//
void PhoneBook::setIndex(int i)
{
	index = i;
}
//int PhoneBook::getIndex(void)
//{
//	return (index);
//}

void PhoneBook::add() {
	if (index == 8)
		index = 0;
	std::cout << "-----New contact-----" << std::endl;
	std::cout << "First Name :" << std::endl;
	std::getline(std::cin,firstName[index]);
	std::cout << "Last Name :" << std::endl;
	std::getline(std::cin, lastName[index]);
	std::cout << "Nick Name:" << std::endl;
	std::getline(std::cin, nickname[index]);
	std::cout << "Phone Number:" << std::endl;
	std::getline(std::cin, phoneNumber[index]);
	std::cout << "Darkest Secret:" << std::endl;
	std::getline(std::cin, darkestSecret[index]);
	++index;
}

void printColumn(std::string column)
{
	int spaces;

	spaces = 10 - column.length();
	if (spaces <= 0)
	{
		std::cout << column.substr(0, 9) << ".";
	}
	else
	{
		std::cout << column;
		for (int i = 0; i < spaces; ++i)
			std::cout << " ";
	}
}

void PhoneBook::getUserInput(void)
{
	std::string input;
	int i;

	input.find_first_not_of(" \n\r\t");
	std::getline(std::cin, input);
	while (input.length() != 1 || !isdigit(input[0]))
	{
		std::cout << "Please provide an index from 0-9" << std::endl;
		std::cin >> input;
	}
	i = atoi(input.c_str());
	std::cout << firstName[i - 1] << std::endl;
}

void PhoneBook::search() {
	std::cout << ANSI_GREEN << "---------------------------------------------" << std::endl;
	std::cout << ANSI_GREEN << "|Index     |First name|Last Name |Nick Name |" << std::endl;
	std::cout << ANSI_GREEN << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; ++i) {
		std::cout << "|";
		std::cout << std::right << i + 1;
		int spaces = 10 - std::to_string(i).length();
		for (int j = 0; j < spaces; j++) {
			std::cout << ' ';
		}
		std::cout << "|";
		printColumn(firstName[i]);
		std::cout << "|";
		printColumn(lastName[i]);
		std::cout << "|";
		printColumn(nickname[i]);
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << ANSI_GREEN << "---------------------------------------------" << std::endl;
	std::cout << "Please provide the index to be printed" << std::endl;
	getUserInput();
	std::cout << ANSI_RESET;
}


int main() {
	std::string prompt;
	PhoneBook phone;

	phone.setIndex(0);
	std::cout << "Type add search or exit" << std::endl;
	std::getline(std::cin, prompt);
	while (prompt.compare("exit") != 0)
	{
		if (prompt.compare("add") == 0)
			phone.add();
		if (prompt.compare("search") == 0)
			phone.search();
		std::cout << "Type add search or exit" << std::endl;
		std::cin >> prompt;
	}
	return (0);
}