/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:40:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/11 10:20:19 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (src == NULL && dst == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
	((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}
