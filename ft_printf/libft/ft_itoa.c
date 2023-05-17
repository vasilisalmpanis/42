/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:41:12 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/17 12:45:51 by valmpani         ###   ########.fr       */
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
	if (c < 0)
		length++;
	while (c != 0)
	{
		c = c / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		value;
	long	number;
	char	*buffer;

	number = (long)n;
	value = ft_find_length(number) + 1;
	buffer = (char *)malloc(value * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[value - 1] = '\0';
	if (number == 0)
		buffer[0] = '0';
	if (number < 0)
	{
		number *= -1;
		buffer[0] = '-';
	}
	while (number != 0)
	{
		buffer[value-- - 2] = number % 10 + '0';
		number = number / 10;
	}
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
