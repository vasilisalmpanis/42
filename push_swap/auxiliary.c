/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:00:28 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/07 09:50:08 by valmpani         ###   ########.fr       */
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
	set_position(*a);
	set_position(*b);
}

void	do_rrotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rrr(a, b);
	}
	set_position(*a);
	set_position(*b);
}

void	do_move(t_node **a, t_node **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	finish_rotation(a, 'a', &cost_a);
	finish_rotation(b, 'b', &cost_b);
	pa(a, b);
}

void	shift_stack(t_node **a)
{
	t_node	*lowest_pos;
	int		stack_size;

	stack_size = lstsize(*a);
	lowest_pos = find_min(*a);
	if (lowest_pos->current_pos > stack_size / 2)
	{
		while (lowest_pos->current_pos != 0)
		{
			rra(a, false);
			set_position(*a);
			lowest_pos = find_min(*a);
		}
	}
	else
	{
		while (lowest_pos->current_pos != 0)
		{
			ra(a, false);
			set_position(*a);
			lowest_pos = find_min(*a);
		}
	}
}
