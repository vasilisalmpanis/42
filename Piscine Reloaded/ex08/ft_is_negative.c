/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:36:54 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/09 17:41:55 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		ft_putchar('P');
	}
	else
	{
		ft_putchar('N');
	}
}

// int main(void)
// {
// 	ft_is_negative(1);
// 	ft_is_negative(2);
// 	ft_is_negative(-4);
// 	ft_is_negative(121219);
// 	ft_is_negative(-1231232);
// 	ft_is_negative(0);
// 	ft_is_negative(00);
// 	ft_is_negative(000);
// 	return(0);
// }