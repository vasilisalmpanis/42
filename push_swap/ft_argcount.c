/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:29:06 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 14:10:21 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argument_count(t_node **a, t_node **b)
{
	if (lstsize(*a) == 2)
		sort_two_params(a);
	else if (lstsize(*a) == 3)
		sort_three_params(a);
	b = NULL;
}

void	sort_two_params(t_node **a)
{
	if ((*a)->x > (*a)->next->x)
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sort_three_params(t_node **a)
{
	t_node	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a, false);
	else if ((*a)->next == max)
		rra(a, false);
	if ((*a)->x > (*a)->next->x)
		sa(a, false);
}
