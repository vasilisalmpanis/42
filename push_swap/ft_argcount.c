/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:29:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/13 13:14:14 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argument_count(t_node **a, t_node **b)
{
	if (is_sorted(*a))
		return ;
	else if (lstsize(*a) == 2)
		sort_two_params(a);
	else if (lstsize(*a) == 3)
		sort_three_params(a, false);
	else if (is_reverse(a, b))
		return ;
	else if (lstsize(*a) == 5)
		sort_five_params(a, b, false);
	else
		push_swap(a, b);
}

void	sort_two_params(t_node **a)
{
	if ((*a)->x > (*a)->next->x)
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sort_three_params(t_node **a, bool value)
{
	t_node	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a, value);
	else if ((*a)->next == max)
		rra(a, value);
	if ((*a)->x > (*a)->next->x)
		sa(a, value);
}

void	sort_five_params(t_node **a, t_node **b, bool value)
{
	t_node	*min;
	t_node	*aftermin;

	min = find_min(*a);
	aftermin = find_aftermin(*a, min);
	while (lstsize(*a) > 3)
	{
		if ((*a)->x == min->x || (*a)->x == aftermin->x)
			pb(a, b);
		else
			ra(a, value);
	}
	sort_three_params(a, value);
	if ((*b)->x < (*b)->next->x)
		sb(b, value);
	while (*b)
		pa(a, b);
}

/*Push numbers in 2 chunks in descending order and keep three and sort them
  find best target, calculate costs and move nodes. If it is not sorted
  rotate list depending on position of index 0 until its position is 0. */
void	push_swap(t_node **a, t_node **b)
{
	push_but_three(a, b);
	sort_three_params(a, false);
	while (*b)
	{
		set_current(a, b);
		move_nodes(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
