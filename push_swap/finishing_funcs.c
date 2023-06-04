/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishing_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:52:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 18:02:14 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_node **a, t_node **b, t_node *best_fit)
{
	while (*a != best_fit->t_n && *b != best_fit)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

void	rrotate_both(t_node **a, t_node **b, t_node *best_fit)
{
	while (*a != best_fit->t_n && *b != best_fit)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}

void	finish_rotation(t_node **list, char name, t_node *best_fit)
{
	while (*list != best_fit)
	{
		if (name == 'a')
		{
			if (best_fit->above_mid)
				ra(list, false);
			else
				rra(list, false);
		}
		else if (name == 'b')
		{
			if (best_fit->above_mid)
				rb(list, false);
			else
				rrb(list, false);
		}
	}
}
