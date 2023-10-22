/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:03:31 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/16 11:03:31 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

void Contacts::formatPrint(std::string buf) {
	if (buf.length() < 10)
		std::cout << std::setw(10) << buf;
	else
		std::cout << buf.substr(0, 9) << ".";
}

void Contacts::printContact() {
	std::cout << "|";
	formatPrint(firstName);
	std::cout << "|";
	formatPrint(lastName);
	std::cout << "|";
	formatPrint(nickname);
	std::cout << "|" <<std::endl;
}

void Contacts::printAllInfo() {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contacts::addContact(){
	while (firstName.empty() || isValidName(firstName))
	{
		std::cout << "First Name :" << std::endl;
		if (!std::getline(std::cin, firstName))
			return ;
	}
	while (lastName.empty() || isValidName(lastName))
	{
		std::cout << "Last Name :" << std::endl;
		if (!std::getline(std::cin, lastName))
			return;
	}
	while (nickname.empty() || isValidName(nickname))
	{
		std::cout << "Nickname :" << std::endl;
		if (!std::getline(std::cin, nickname))
			return;
	}
	while (phoneNumber.empty() || isNotAllNum())
	{
		std::cout << "Phone Number :" << std::endl;
		if (!std::getline(std::cin, phoneNumber))
			return;
	}
	while (darkestSecret.empty())
	{
		std::cout << "Darkest Secret:" << std::endl;
		if (!std::getline(std::cin, darkestSecret))
			return;
	}
	filled = 1;
};

void Contacts::clearContact() {
	firstName.clear();
	lastName.clear();
	nickname.clear();
	phoneNumber.clear();
	darkestSecret.clear();
	filled = 0;
}

int Contacts::getStatus() {
	return (filled);
}

int Contacts::isNotAllNum() {
	int i;

	i = -1;
	while (phoneNumber[++i])
	{
		if (!isdigit(phoneNumber[i]))
		{
			std::cout << ANSI_RED<< "Please provide a valid number." << ANSI_RESET << std::endl;
			return (1);
		}
	}
	return (0);
}

int Contacts::isValidName(std::string buf)
{
	int i;

	i = -1;
	while (buf[++i])
	{
		if (isdigit(buf[i]))
		{
			std::cout << ANSI_RED<< "Please provide a valid name." << ANSI_RESET << std::endl;
			return (1);
		}

	}
	return (0);
}

Contacts::Contacts(){
};

Contacts::~Contacts(){
};
