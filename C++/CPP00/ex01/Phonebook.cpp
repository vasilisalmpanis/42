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

void PhoneBook::add() {
	if (index == 8)
		index = 0;
	std::cout << "-----New contact-----" << std::endl;
	std::cout << "First Name :" << std::endl;
	std::cin >> firstName[index];
	std::cout << "Last Name :" << std::endl;
	std::cin >> lastName[index];
	std::cout << "Nick Name:" << std::endl;
	std::cin >> nickname[index];
	std::cout << "Phone Number:" << std::endl;
	std::cin >> phoneNumber[index];
	std::cout << "Darkest Secret:" << std::endl;
	std::cin >> darkestSecret[index];
	++index;
}

void PhoneBook::search() {
	std::cout << "Index     |First name|Last Name |Nick Name" << std::endl;
	for (int i = 0; i < index; ++i) {
		std::cout << std::right << i;
		int spaces = 9 - std::to_string(i).length(); // Change 'index' to 'i' here
		for (int j = 0; j < spaces; j++) {
			std::cout << ' ';
		}
		std::cout << " | " << (firstName[i].length() > 10 ? firstName[i].substr(0, 10) + '.' : firstName[i])
				  << " | " << (lastName[i].length() > 10 ? lastName[i].substr(0, 10) + '.' : lastName[i])
				  << " | " << (nickname[i].length() > 10 ? nickname[i].substr(0, 10) + '.' : nickname[i])
				  << std::endl;
	}
}


int main() {
	std::string prompt;
	PhoneBook phone;

	std::cout << "Type ADD SEARCH or EXIT" << std::endl;
	std::cin >> prompt;
	while (prompt.compare("EXIT") != 0)
	{
		if (prompt.compare("ADD") == 0)
			phone.add();
		if (prompt.compare("SEARCH") == 0)
			phone.search();
		std::cout << "Type ADD SEARCH or EXIT" << std::endl;
		std::cin >> prompt;
	}
	return (0);
}