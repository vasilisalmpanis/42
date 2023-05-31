/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:30:35 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/11 12:10:40 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			index;
	int				count;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)(dst);
	s = (unsigned char *)(src);
	count = +1;
	if (dst > src)
	{
		d = (unsigned char *)(dst + len - 1);
		s = (unsigned char *)(src + len - 1);
		count = -1;
	}
	index = 0;
	while (index < len)
	{
		*d = *s;
		d += count;
		s += count;
		index++;
	}
	return (dst);
}
