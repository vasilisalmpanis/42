/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:55:51 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/05 11:27:36 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node *a)
{
	bool	sorted;

	sorted = true;
	while (a->next != NULL)
	{
		if (a->next->x < a->x)
			return (false);
		a = a->next;
	}
	return (sorted);
}

bool	is_reverse(t_node **a, t_node **b)
{
	bool	reverse;
	t_node	*temp;
	t_node	*min;

	reverse = true;
	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->next->x > temp->x)
			return (false);
		temp = temp->next;
	}
	min = find_min(*a);
	while (*a != min)
		pb(a, b);
	while (*b)
	{
		pa(a, b);
		ra(a, false);
	}
	return (reverse);
}
