/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:04:07 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 09:13:25 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		ft_putchar(str[index]);
		index++;
	}
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc > 1)
	{
		index = 1;
		while (index != argc)
		{
			ft_putstr(argv[index]);
			ft_putstr("\n");
			index++;
		}
	}
	return (0);
}
