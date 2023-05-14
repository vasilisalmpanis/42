/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:20:32 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/14 13:30:42 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar(48 + n % 10, fd);
	}
}
