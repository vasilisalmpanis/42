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

PhoneBook::PhoneBook(void)
{
	clearContacts();
	index = 0;
}

PhoneBook::~PhoneBook(void) {
}

void PhoneBook::setIndex(int i)
{
	index = i;
}

void PhoneBook::add() {
	if (index == 7)
		index = -1;
	if (contacts[++index].getStatus())
	{
		std::cout << ANSI_RED << "The oldest contact was just deleted." << ANSI_RESET << std::endl;
		contacts[index].clearContact();
	}
	contacts[index].addContact();

}

void PhoneBook::clearContacts() {
	int i;

	i = -1;
	while (++i < 8)
	{
		contacts[i].clearContact();
	}
}

void PhoneBook::printContact(void)
{
	int i;

	i = -1;
	std::cout << std::right;
	while (++i < 8)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		contacts[i].printContact();
	}
}

void PhoneBook::getUserInput(void)
{
	std::string input;
	int i;

	while (true) {
		std::cout << "Please provide an index from 1-8: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Invalid input. Please provide an index from 1-8." << std::endl;
		else
		{
			input = input.substr(input.find_first_not_of(" \n\r\t"), input.find_last_not_of(" \n\r\t") + 1);
			if (input.length() == 1 && input[0] >= '1' && input[0] <= '8') {
				break ;
			} else {
				std::cout << "Invalid input. Please provide an index from 1-8." << std::endl;
			}
		}
	}
	i = atoi(input.c_str());
	if (contacts[i - 1].getStatus())
		contacts[i - 1].printAllInfo();
}

void PhoneBook::search() {
	std::cout << ANSI_GREEN << "---------------------------------------------" << std::endl;
	std::cout << ANSI_GREEN << "|     Index|First name| Last Name| Nick Name|" << std::endl;
	std::cout << ANSI_GREEN << "|----------|----------|----------|----------|" << std::endl;
	printContact();
	std::cout << ANSI_GREEN << "---------------------------------------------" << std::endl;
	getUserInput();
	std::cout << ANSI_RESET;
}
