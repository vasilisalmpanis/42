/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:03:31 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/16 11:03:31 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP
# include <iostream>
# include <iomanip>
# define ANSI_RESET "\033[0m"
# define ANSI_RED "\033[31m"
# define ANSI_GREEN "\033[38;5;119m"
# define ANSI_YELLOW "\033[33m"
# define ANSI_BLUE "\033[34m"

class Contacts {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	int	filled;
public:
	Contacts();
	~Contacts();
	void printContact();
	void formatPrint(std::string buf);
	void printAllInfo();
	void addContact();
	void clearContact();
	int isValidName(std::string buf);
	int isNotAllNum();
	int	getStatus();
};
#endif