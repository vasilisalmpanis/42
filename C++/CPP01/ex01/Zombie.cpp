/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:46 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 11:52:33 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << name << " destroyed." << std::endl;
}

void Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name = name;
}
