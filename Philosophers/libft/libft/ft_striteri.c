/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:24:24 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/14 12:17:08 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	if (l == 0)
		return ;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
