/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 09:56:26 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/13 11:25:02 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_total_length(char *s1, char *s2)
{
	size_t	length_s1;
	size_t	length_s2;

	length_s1 = 0;
	length_s2 = 0;
	if (s1)
		length_s1 = ft_strlen(s1);
	if (s2)
		length_s2 = ft_strlen(s2);
	return (length_s1 + length_s2);
}

char	*ft_append(char *final, char *s1, char *s2, size_t total_length)
{
	if (total_length == 1)
		return ("\0");
	while (*s1)
	{
		*final++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*final++ = *s2;
		s2++;
	}
	*final = '\0';
	return (final - total_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_length;
	char	*last_buffer;

	if (!s1 && !s2)
		return (malloc(1 * sizeof(char)));
	total_length = ft_total_length((char *)s1, (char *)s2);
	last_buffer = malloc((total_length + 1) * sizeof(char));
	if (!last_buffer)
		return (NULL);
	last_buffer = ft_append(last_buffer, (char *)s1, (char *)s2, total_length);
	return (last_buffer);
}

// int main()
// {
// 	char *s1 = "";
// 	char *s2 = "";
// 	char *s3;

// 	s3 = ft_strjoin(s1, s2);
// 	printf("%s\n", s3);
// }