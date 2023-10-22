/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:46:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/16 17:46:39 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	std::string prompt;
	PhoneBook phone;

	phone.setIndex(-1);
	std::cout << "Type ADD SEARCH or EXIT" << std::endl;
	std::getline(std::cin, prompt);
	while (prompt.compare("EXIT") != 0)
	{
		if (prompt.compare("ADD") == 0)
			phone.add();
		if (prompt.compare("SEARCH") == 0)
			phone.search();
		std::cout << "Type ADD SEARCH or EXIT" << std::endl;
		if (!std::getline(std::cin, prompt))
			return (1);
	}
	return (0);
}
