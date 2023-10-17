/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:26:32 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 17:26:32 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace_content(std::string line, char *s1, char *s2)
{
	size_t index;
	index = line.find(s1);
	while (index)
}

int main(int argc, char **argv)
{
	std::fstream fs;
	std::fstream re;
	std::string line;
	std::string *ptr;
	if (argc != 4)
	{
		std::cout << "Please provide 3 arguments." << std::endl;
		return (1);
	}
	std::fstream file("replacement.txt", std::ios::out);
	fs.open("out");
	re.open("replacement.txt", std::ios::out);
	while (fs.good())
	{
		getline(fs, line);
		replace_content(line, argv[2], argv[3]);
		re.write(line.c_str(), line.length());
		re.write("\n", 1);
	}
	return (0);
}
