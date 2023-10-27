/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:16:10 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 15:16:10 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include "HumanB.h"

int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		club.setType("some other type of club");
		jim.attack();
	}
}
