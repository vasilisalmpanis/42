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