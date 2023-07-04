/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:16:22 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/11 14:47:26 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*scopy;

	scopy = (char *)s;
	index = 0;
	c = c % 128;
	while (scopy[index])
	{
		if (((char *)scopy)[index] == c)
		{
			scopy += index;
			return (scopy);
		}
		index++;
	}
	if (((char *)scopy)[index] == c)
	{
		scopy += index;
		return (scopy);
	}
	return (NULL);
}
