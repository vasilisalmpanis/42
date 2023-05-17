/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:08:59 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/17 21:32:11 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_character(int c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

void	ft_putstr(char *c, int *length)
{
	if (c == NULL)
	{
		write(1, "(null)", 6);
		*length += 1;
	}
	else
	{
		*length += ft_strlen(c);
		write(1, c, ft_strlen(c));
	}
}

void	ft_putptr(unsigned long arg, int *length)
{
	if (arg == 0)
	{
		ft_putstr("0x0", length);
		*length += 3;
		return ;
	}
	ft_putstr("0x", length);
	ft_hexa(arg, length);
}

void	ft_printnbr(char c, int arg, int *length)
{
	char	*nbr;

	if (c == 'd' || c == 'i')
	{
		nbr = ft_itoa(arg);
		ft_putstr(nbr, length);
		free(nbr);
	}
	else if (c == 'u')
	{
		ft_putunsigned((unsigned int) arg, "0123456789", length);
	}
	if (c == 'x')
		ft_putnbrhex(c, arg, "0123456789abcdef", length);
	else if (c == 'X')
		ft_putnbrhex(c, arg, "0123456789ABCDEF", length);
}
