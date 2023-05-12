/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:55:32 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/12 13:32:55 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	r;
	size_t	length;
	char	*bdst;
	char	*bsrc;

	bdst = dst;
	bsrc = (char *)src;
	r = dstsize;
	while (r-- != 0 && *bdst != '\0')
		bdst++;
	length = bdst - dst;
	r = dstsize - length;
	if (r == 0)
		return (length + ft_strlen(src));
	while (*bsrc != '\0')
	{
		if (r > 1)
		{
			*bdst++ = *bsrc;
			r--;
		}
		bsrc++;
	}
	*bdst = '\0';
	return (length + (bsrc - src));
}
