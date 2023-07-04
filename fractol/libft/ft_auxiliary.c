/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:29:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 11:03:16 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbrhex(char c, unsigned int arg, char *base, int *length)
{
	if (arg >= ft_strlen(base))
		ft_putnbrhex(c, arg / ft_strlen(base), base, length);
	write(1, &base[arg % ft_strlen(base)], 1);
	*length += 1;
}
