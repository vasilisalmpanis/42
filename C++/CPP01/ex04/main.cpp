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

void replace_content(std::string &output, std::string oldString, std::string newString)
{
	size_t index;

	index = output.find(oldString);
	while (index != std::string::npos)
	{
		output.erase(index, oldString.length());
		output.insert(index, newString);
		index = output.find(oldString);
	}
}

int main(int argc, char **argv)
{
	std::fstream fs;
	std::fstream re;
	std::string line;
	std::string output;
	if (argc != 4)
	{
		std::cout << "Please provide 3 arguments." << std::endl;
		return (1);
	}
	std::fstream file("replacement.txt", std::ios::out);
	fs.open(argv[1]);
	if (!fs.good())
	{
		std::cout << "Please provide a valid filename." << std::endl;
		return (1);
	}
	re.open("replacement.txt", std::ios::out);
	while (fs.good())
	{
		getline(fs, line);
		output.append(line);
		output.append("\n");
	}
	replace_content(output, argv[2], argv[3]);
	output.pop_back();
	re << output;
	re.close();
	return (0);
}
