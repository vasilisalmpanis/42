/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:38:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/13 13:35:40 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	final_length;

	if (!s1)
		return (ft_calloc(1, 1));
	if (!set)
		return ((char *)s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	final_length = ft_strlen(s1);
	while (s1[final_length - 1] && ft_strchr(set, s1[final_length - 1]))
		final_length--;
	return (ft_substr(s1, 0, final_length));
}
