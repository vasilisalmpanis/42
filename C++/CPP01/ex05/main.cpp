/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:43:02 by valmpani          #+#    #+#             */
/*   Updated: 2023/10/27 18:55:47 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(void)
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("WARfkjbdfkNING");
	return (0);
}