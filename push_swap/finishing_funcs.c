/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:52:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/06 11:29:34 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_node **list, char name, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (name == 'a')
				ra(list, false);
			else
				rb(list, false);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (name == 'a')
				rra(list, false);
			else
				rrb(list, false);
			(*cost)++;
		}
	}
}
