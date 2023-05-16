/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:07:33 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 08:50:28 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	half;
	int	index;

	if (nb <= 0)
	{
		return (0);
	}
	else if (nb == 1)
	{
		return (1);
	}
	index = 1;
	half = nb / 2;
	while (index <= half)
	{
		if (index * index == nb)
			return (index);
		index++;
	}
	return (0);
}

// int main(void)
// {
// 	printf("%d\n", ft_sqrt(520685508));
// 	return (0);
// }