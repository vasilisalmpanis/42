/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:29:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 16:04:51 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argument_count(t_node **a, t_node **b)
{
	if (lstsize(*a) == 2)
		sort_two_params(a);
	else if (lstsize(*a) == 3)
		sort_three_params(a, false);
	else
		push_swap(a, b);
	// ft_putnbr_fd(lstsize(*a), 1);
	// ft_putnbr_fd(lstsize(*b), 1);
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

void	push_swap(t_node **a, t_node **b)
{
	t_node	*min;

	while (lstsize(*a) > 3)
		pb(a, b);
	sort_three_params(a, false);
	while (*b)
	{
		set_current(a, b);
		move_nodes(a, b);
	}
	min = find_min;
	if (min->above_mid)
		while (*a != min)
			ra(a, false);
	else
		while (*a != min)
			rra(a, false);
}
