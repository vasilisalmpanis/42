/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:06:34 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/14 11:23:35 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			l;
	char			*b;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l == 0)
		return (ft_calloc(1, sizeof(char)));
	b = ft_calloc((l + 1), sizeof(char));
	if (!b)
		return (NULL);
	while (i < l)
	{
		b[i] = f(i, s[i]);
		i++;
	}
	return (b);
}
