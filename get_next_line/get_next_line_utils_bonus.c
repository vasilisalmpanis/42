/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:29:19 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/23 12:39:08 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	index;

	index = 0;
	while (c[index])
	{
		index++;
	}
	return (index);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	char	*last_buffer;

	if (!s1 && !s2)
		return (malloc(1 * sizeof(char)));
	total_length = ft_strlen(s1) + ft_strlen(s2);
	last_buffer = malloc((total_length + 1) * sizeof(char));
	if (!last_buffer)
		return (NULL);
	while (*s1)
	{
		*last_buffer++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*last_buffer++ = *s2;
		s2++;
	}
	*last_buffer = '\0';
	last_buffer -= total_length;
	return (last_buffer);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	index;

	index = 0;
	if (count == 0 || size == 0)
		return (ptr = malloc(count * size));
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	while (index < (count * size))
	{
		((unsigned char *)ptr)[index] = '\0';
		index++;
	}
	return ((unsigned char *)ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((unsigned char *)s)[index] = 0;
		index++;
	}
}
