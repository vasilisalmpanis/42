/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:17:46 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/09 18:36:25 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

// int main(void)
// {
// 	printf("%d \n", ft_recursive_factorial(0));
// 	printf("%d \n", ft_recursive_factorial(-10));
// 	printf("%d \n", ft_recursive_factorial(10));
// 	printf("%d \n", ft_recursive_factorial(5));
// 	return (0);
// }