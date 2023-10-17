/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:46:46 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/17 11:47:26 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
private:
	std::string name;
public:
	Zombie();
	~Zombie();
	void set_name(std::string name);
	void announce();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif
