/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:41:12 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/13 20:19:44 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_find_length(long c)
{
	int	length;

	length = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c = c / 10;
		length++;
	}
	return (length);
}

int	ft_is_pn(long c)
{
	if (c >= 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	long	value;
	long	number;
	char	*buffer;

	number = n;
	value = ft_find_length(n) + 1;
	if (number < 0)
	{
		number *= -1;
		value++;
	}
	buffer = ft_calloc(value, 1);
	if (!buffer)
		return (NULL);
	while (value > 0)
	{
		buffer[value - 2] = number % 10 + '0';
		number = number / 10;
		value--;
	}
	if (n < 0)
		buffer[0] = '-';
	return (buffer);
}

// int	main(void)
// {
// 	char *s;
// 	s = ft_itoa(-1234);

// 	// s = ft_itoa(1);

// 	// s = ft_itoa(-1);
// 	// s = ft_itoa(42);
// 	printf("%s", s);
// 	free(s);
// 	return 0;
// }
