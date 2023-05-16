/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:49:36 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 15:39:44 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	index;

	index = 0;
	while (index < length)
	{
		(*f)(tab[index]);
		index++;
	}
}

// void print_element(int element)
// {
//     printf("%d ", element);
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     ft_foreach(arr, len, &print_element);

//     return 0;
// }