/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:58:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/05 12:50:11 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_node *b)
{
	int	i;
	int	center;

	if (!b)
		return ;
	i = 0;
	center = lstsize(b) / 2;
	while (b)
	{
		b->current_pos = i;
		if (i <= center)
			b->above_mid = true;
		else
			b->above_mid = false;
		b = b->next;
		i++;
	}
}

void	set_best_fit(t_node **b)
{
	long	best_price;
	t_node	*best_node;
	t_node	*list;

	list = *b;
	if (list == NULL)
		return ;
	best_price = INT64_MAX;
	while (list)
	{
		if (list->push_price < best_price)
		{
			best_price = list->push_price;
			best_node = list;
		}
		list = list->next;
	}
	best_node->best_fit = true;
}

t_node	*get_best_fit(t_node *list)
{
	if (list == NULL)
		return (NULL);
	while (list)
	{
		if (list->best_fit)
			return (list);
		list = list->next;
	}
	return (list);
}

void	set_current(t_node **a, t_node **b)
{
	set_position(*a);
	set_position(*b);
	target_node(a, b);
	set_price(a, b);
	set_best_fit(b);
}

void	move_nodes(t_node **a, t_node **b)
{
	t_node	*best_fit;

	best_fit = get_best_fit(*b);
	if (best_fit->above_mid && best_fit->t_n->above_mid)
		rotate_both(a, b, best_fit);
	else if (!(best_fit->above_mid) && !(best_fit->t_n->above_mid))
		rrotate_both(a, b, best_fit);
	finish_rotation(b, 'b', best_fit);
	finish_rotation(a, 'a', best_fit->t_n);
	pa(a, b);
}
