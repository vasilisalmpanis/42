/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:04:25 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/15 22:27:45 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i1;
	size_t	i2;
	char	*h;

	i1 = 0;
	h = (char *)haystack;
	if (!*needle)
		return (h);
	while (haystack[i1] != '\0' && i1 < len)
	{
		i2 = 0;
		while (h[i1 + i2] == needle[i2] && h[i1] != '\0' && (i1 + i2 < len))
		{
			if (needle[i2 + 1] == '\0')
			{
				return (&h[i1]);
			}
			i2++;
		}
		i1++;
	}
	return (NULL);
}
