/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:28:24 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/12 12:28:24 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "iostream"
# include "stdlib.h"

# define ANSI_RESET "\033[0m"
# define ANSI_RED "\033[31m"
# define ANSI_GREEN "\033[38;5;119m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_BLUE "\033[34m"

class PhoneBook {
private:
	std::string firstName[8];
	std::string lastName[8];
	std::string nickname[8];
	std::string phoneNumber[8];
	std::string darkestSecret[8];
	int index;
public:
//	void setFirstName(std::string string, int index);
//	std::string setFirstName(int i);
//	void setLastName(std::string string, int index);
//	std::string setLastName(int i);
//	void setNickname(std::string string, int index);
//	std::string setNickname(int i);
//	void setPhoneNumber(std::string string, int index);
//	std::string getPhoneNumber(int i);
//	void setDarkestSecret(std::string string, int index);
//	std::string getDarkestSecret(int i);
	void setIndex(int index);
//	int getIndex(void);
	void add(void);
	void search(void);
	void getUserInput(void);
	void clearContact(void);
	PhoneBook (void);
	~PhoneBook(void);
};

#endif