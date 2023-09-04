/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:34:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/19 16:54:31 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*last_buffer;

	index = 0;
	if (!s || (size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	index = ft_strlen(s + start);
	if (len > index)
		len = index;
	last_buffer = malloc((len + 1) * sizeof(char));
	if (!last_buffer)
		return (NULL);
	ft_strlcpy(last_buffer, s + start, len + 1);
	return (last_buffer);
}

// int main()
// {
// 	char *s = "hello world";
// 	char *d;