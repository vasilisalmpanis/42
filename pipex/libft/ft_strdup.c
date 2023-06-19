/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:10:03 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/12 17:21:34 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!dest)
		return (0);
	ft_memcpy(dest, s1, ft_strlen(s1));
	return (dest);
}
