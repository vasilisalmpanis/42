/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:38:31 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/27 19:04:49 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	int n = 5;
	zombie = zombieHorde(5, "vasilis");
	for (int i = 0; i < n; ++i) {
		zombie[i].announce();
	}
	zombie = zombieHorde(1, "dkjghjdg");
	if (zombie)
		delete [] zombie;
	return (1);
}
