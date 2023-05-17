/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:34:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/12 23:31:55 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*last_buffer;

	index = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	last_buffer = malloc((len + 1) * sizeof(char));
	if (!last_buffer)
		return (NULL);
	while (index < len)
	{
		last_buffer[index] = s[index + start];
		index++;
	}
	last_buffer[index] = '\0';
	return (last_buffer);
}

// int main()
// {
// 	char *s = "hello world";
// 	char *d;