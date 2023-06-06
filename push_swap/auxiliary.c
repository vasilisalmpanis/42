/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:00:28 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/06 11:39:11 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	do_rotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

void	do_rrotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rrr(a, b);
	}
}

void	do_move(t_node **a, t_node **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rrotate_both(a, b, &cost_a, &cost_b);
	finish_rotation(a, 'a', &cost_a);
	finish_rotation(b, 'b', &cost_b);
	pa(a, b);
}

void	shift_stack(t_node **a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = lstsize(*a);
	lowest_pos = find_min(*a)->current_pos;
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(a, false);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(a, false);
			lowest_pos--;
		}
	}
}