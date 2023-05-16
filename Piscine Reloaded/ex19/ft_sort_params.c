/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:14:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 10:03:39 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	ft_sort_tab(int size, char **tab)
{
	int	x;
	int	y;

	x = 1;
	while (x != 0)
	{
		x = 0;
		y = 1;
		while (y < (size - 1))
		{
			if (ft_strcmp(tab[y], tab[y + 1]) > 0)
			{
				ft_swap(&tab[y], &tab[y + 1]);
				x++;
			}
			y++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc > 2)
	{
		ft_sort_tab(argc, argv);
	}
	index = 1;
	while (index != argc)
	{
		ft_putstr(argv[index]);
		ft_putstr("\n");
		index++;
	}
	return (0);
}
