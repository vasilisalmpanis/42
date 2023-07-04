/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 09:56:26 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/19 16:51:28 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (total_length == 1)
		return ("\0");
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
