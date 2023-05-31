/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:36:57 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/31 18:12:54 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makelist(int argc, char **argv)
{
	int	result;
	int	i;

	if (argc != 2)
	{
		i = 0;
		while (argv[++i])
		{
			result = ft_atoi(argv[i]);
			printf("%d\n", result);
		}
	}
}
