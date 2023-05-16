/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:08:10 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 11:52:55 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	temp;
	int	*res;
	int	index;

	if (min >= max)
	{
		return (0);
	}
	temp = max - min;
	res = (int *)malloc(sizeof(int) * temp);
	if (res == NULL)
		return (0);
	index = 0;
	while (min < max)
	{
		res[index] = min;
		min++;
		index++;
	}
	return (res);
}

// int main(void)
// {
// 	int *array;
// 	array = ft_range(0,10);
// 	free(array);
// }
