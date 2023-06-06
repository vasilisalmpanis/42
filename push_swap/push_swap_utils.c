/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:47:17 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/06 09:02:35 by valmpani         ###   ########.fr       */
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

t_node	*find_aftermin(t_node *list, t_node *min)
{
	long	max;
	t_node	*aftermin;

	max = INT64_MAX;
	while (list)
	{
		if (list->x > min->x && list->x < max)
		{
			max = list->x;
			aftermin = list;
		}
		list = list->next;
	}
	return (aftermin);
}

void	target_node(t_node **a, t_node **b)
{
	t_node	*current;
	t_node	*current_b;
	t_node	*target_node;
	long	best_value;

	current_b = *b;
	while (current_b)
	{
		best_value = INT64_MAX;
		current = *a;
		while (current)
		{
			if (current->x > current_b->x && current->x < best_value)
			{
				best_value = current->x;
				target_node = current;
			}
			current = current->next;
		}
		if (best_value == INT64_MAX)
			current_b->t_n = find_min(*a);
		else
			current_b->t_n = target_node;
		current_b = current_b->next;
	}
}

void	set_price(t_node **a, t_node **b)
{
	int		len_a;
	int		len_b;
	t_node	*current_b;

	len_a = lstsize(*a);
	len_b = lstsize(*b);
	current_b = *b;
	while (current_b)
	{
		current_b->push_price = current_b->current_pos;
		if (!current_b->above_mid)
			current_b->push_price = len_b - current_b->current_pos;
		if (current_b->t_n->above_mid)
			current_b->push_price += current_b->t_n->push_price;
		else
			current_b->push_price += len_a - (current_b->t_n->current_pos);
		current_b = current_b->next;
	}
}

void	push_but_three(t_node **a, t_node **b)
{
	int	len;
	int	count;
	int	i;

	len = lstsize(*a);
	count = 0;
	i = 0;
	while (i < len && count < len / 2)
	{
		if ((*a)->index <= len / 2)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a, false);
		i++;
	}
	while (len - count > 3)
	{
		pb(a, b);
		count++;
	}
}