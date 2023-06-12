/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:58:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/12 08:32:04 by valmpani         ###   ########.fr       */
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

void	set_current(t_node **a, t_node **b)
{
	set_position(*a);
	set_position(*b);
	target_node(a, b);
	set_price(a, b);
}

/* Sets price + if above half of list and - if below because we have
to rr. also sets price for the target node to go to the top. If both postive
we rr if both negative we rrr else every list rotates how it needs to.*/
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

/* Sets index but setting min value on each iteration
and the find the next smaller biggest number. Could also be implemented
in reverse. */
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
