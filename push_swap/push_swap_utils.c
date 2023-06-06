/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:47:17 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/06 10:55:26 by valmpani         ###   ########.fr       */
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
			if (current->index > current_b->index && current->index < best_value)
			{
				best_value = current->index;
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
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = lstsize(tmp_a);
	size_b = lstsize(tmp_b);
	while (tmp_b)
	{
		tmp_b->price_b = tmp_b->current_pos;
		if (tmp_b->current_pos > size_b / 2)
			tmp_b->price_b = (size_b - tmp_b->current_pos) * -1;
		tmp_b->price_a = tmp_b->t_n->current_pos;
		if (tmp_b->t_n->current_pos > size_a / 2)
			tmp_b->price_a = (size_a - tmp_b->t_n->current_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	set_index(t_node *a, int len)
{
	t_node	*ptr;
	t_node	*highest;
	int		value;

	while (--len > 0)
	{
		ptr = a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->x == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->x > value && ptr->index == 0)
			{
				value = ptr->x;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = len;
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