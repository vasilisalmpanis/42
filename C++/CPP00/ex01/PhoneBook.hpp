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
# include "string.h"

class PhoneBook {
private:
	std::string Contacts[8];
	std::string firstName[8];
	std::string lastName[8];
	std::string nickname[8];
	std::string phoneNumber[8];
	std::string darkestSecret[8];
	int index;
public:
	void add(void);
	void search(void);
	PhoneBook (void);
	~PhoneBook(void);
};

#endif