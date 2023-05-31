/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:01:33 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/11 15:23:48 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		step;
	int		boolean;

	c = c % 128;
	boolean = 0;
	index = -1;
	step = 0;
	while (s[++index])
	{
		if (s[index] == c)
		{
			step = index;
			boolean = 1;
		}
	}
	if (s[index] == c)
	{
		step = index;
		boolean = 1;
	}
	if (boolean == 1)
		return ((char *)(s + step));
	else
		return (NULL);
}
