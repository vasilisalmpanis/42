/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:58:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/06 13:55:11 by valmpani         ###   ########.fr       */
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

		b = b->next;
		i++;
	}
}

// void	set_best_fit(t_node **b)
// {
// 	long	best_price;
// 	t_node	*best_node;
// 	t_node	*list;

// 	list = *b;
// 	if (list == NULL)
// 		return ;
// 	best_price = INT_MAX;
// 	while (list)
// 	{
// 		if (list->push_price < best_price)
// 		{
// 			best_price = list->push_price;
// 			best_node = list;
// 		}
// 		list = list->next;
// 	}
// 	best_node->best_fit = true;
// }

// t_node	*get_best_fit(t_node *list)
// {
// 	if (list == NULL)
// 		return (NULL);
// 	while (list)
// 	{
// 		if (list->best_fit)
// 			return (list);
// 		list = list->next;
// 	}
// 	return (list);
// }

void	set_current(t_node **a, t_node **b)
{
	set_position(*a);
	set_position(*b);
	target_node(a, b);
	set_price(a, b);
}

void	move_nodes(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*c_n;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->price_a) + nb_abs(tmp->price_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->price_b) + nb_abs(tmp->price_a);
			cost_a = tmp->price_a;
			cost_b = tmp->price_b;
			c_n = tmp;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
