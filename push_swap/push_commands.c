/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:30:39 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 15:53:20 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **src)
{
	t_node	*node;

	if (*src == NULL || src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*dest == NULL)
	{
		*dest = node;
		(*dest)->next = NULL;
	}
	else
	{
		node->next = *dest;
		*dest = node;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
