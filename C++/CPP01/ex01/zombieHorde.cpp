/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:14:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 14:14:25 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie;

	zombie = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		zombie[i].set_name(name);
	}
	return (zombie);
}