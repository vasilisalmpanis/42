/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:14:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/27 19:04:06 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie;

	if (N <= 0)
	{
		std::cout << "Please provide a positive number to be created" << std::endl;
		return (NULL);
	}
	zombie = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		zombie[i].set_name(name);
	}
	return (zombie);
}
