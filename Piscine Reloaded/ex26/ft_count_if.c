/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:08:21 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/10 15:40:20 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	while (tab[index] != NULL)
	{
		if ((*f)(tab[index]) == 1)
		{
			result++;
		}
		index++;
	}
	return (result);
}
