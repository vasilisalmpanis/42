/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:53:24 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:02 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *p;
	std::string & r = string;
	p = &string;

	std::cout << "Original: " <<&string << std::endl;
	std::cout << "Ref: " <<&r << std::endl;
	std::cout << "Pointer: " <<&p << std::endl;

	std::cout << "Value Original: " <<string << std::endl;
	std::cout << "Value Ref: " <<r << std::endl;
	std::cout << "Value Pointer: " << p << std::endl;
	return (1);
}