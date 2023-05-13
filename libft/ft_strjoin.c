/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 09:56:26 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/13 09:59:12 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length_s1;
	size_t	length_s2;
	char	*last_buffer;

	length_s1 = 0;
	length_s2 = 0;
	if (s1)
		length_s1 = ft_strlen(s1);
	if (s2)
		length_s2 = ft_strlen(s2);
}