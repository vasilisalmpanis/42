/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:43:02 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 19:43:02 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int find_level(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i) {
		if (level.compare(levels[i]) == 0)
			return (i + 1);
	}
	return (-1);
}

void filter(std::string level, Harl harl)
{
	switch (find_level(level)) {
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	filter(argv[1], harl);
	return (0);
}