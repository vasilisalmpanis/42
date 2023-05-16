/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:05:32 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 10:19:32 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(char *src)
{
	char	*temp;
	int		index;

	index = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[index] != '\0')
	{
		temp[index] = src[index];
		index++;
	}
	temp[index] = '\0';
	return (temp);
}

// #include <stdio.h>
// int main(void)
// {
// 	char src[] = "43597234uyegfjkvfguywej7364t8q";

// 	printf("%s\n", ft_strdup(src));
// }
