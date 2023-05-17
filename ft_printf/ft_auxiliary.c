/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:29:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/17 21:31:49 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long arg, int *length)
{
	char			*base;
	int				temp;

	base = "0123456789abcdef";
	if (arg >= 16)
		ft_hexa(arg / 16, length);
	temp = base[arg % 16];
	write(1, &temp, 1);
	*length += 1;
}

void	ft_putunsigned(unsigned int nbr, char *base, int *length)
{
	if (nbr >= 10)
		ft_putunsigned((nbr / 10), base, length);
	*length += 1;
	write(1, &base[nbr % 10], 1);
}

void	ft_putnbrhex(char c, unsigned int arg, char *base, int *length)
{
	if (arg >= 16)
		ft_putnbrhex(c, arg / 16, base, length);
	write(1, &base[arg % 16], 1);
	*length += 1;
}
