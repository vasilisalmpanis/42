/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:12:12 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 15:12:12 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string weapon) {
	type = weapon;
}
Weapon::~Weapon() {}

void Weapon::setType(std::string weapon) {
	this->type = weapon;
}

const std::string& Weapon::getType() const {
	return (type);
}