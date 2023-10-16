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
# include "Contacts.hpp"

# define ANSI_RESET "\033[0m"
# define ANSI_RED "\033[31m"
# define ANSI_GREEN "\033[38;5;119m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_BLUE "\033[34m"

class PhoneBook {
private:
	Contacts contacts[8];
	int index;
public:
	void setIndex(int index);
	void add(void);
	void search(void);
	void getUserInput(void);
	void clearContacts(void);
	void printContact(void);
	PhoneBook (void);
	~PhoneBook(void);
};

#endif