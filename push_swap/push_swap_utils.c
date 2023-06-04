/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:47:17 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 15:26:40 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_node *list)
{
	t_node	*max;

	if (list == NULL)
		return (NULL);
	max = list;
	while (list != NULL)
	{
		if (list->x > max->x)
			max = list;
		list = list->next;
	}
	return (max);
}

t_node	*find_min(t_node *list)
{
	t_node	*min;

	if (list == NULL)
		return (NULL);
	min = list;
	while (list != NULL)
	{
		if (list->x < min->x)
			min = list;
		list = list->next;
	}
	return (min);
}

void	target_node(t_node *a, t_node *b)
{
	t_node	*current;
	t_node	*target_node;
	long	best_value;

	while (b)
	{
		best_value = INT64_MAX;
		current = a;
		while (a)
		{
			if (current->x > b->x && current->x < best_value)
			{
				best_value = current->x;
				target_node = current;
			}
			current = current->next;
		}
	}
	if (best_value == INT64_MAX)
		b->t_n = find_min(a);
	else
		b->t_n = target_node;
	b = b->next;
}

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(a);
	len_b = lstsize(b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!b->above_mid)
			b->push_price = len_b - b->current_pos;
		if (b->t_n->above_mid)
			b->push_price += b->t_n->push_price;
		else
			b->push_price += len_a - (b->t_n->current_pos);
		b = b->next;
	}
}