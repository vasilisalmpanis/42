/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:08:26 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/12 16:20:10 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
