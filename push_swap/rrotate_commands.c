/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:06:44 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/03 12:08:57 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **list)
{
	t_node	*last_node;
	t_node	*current;

	if (list == NULL || *list == NULL)
		return ;
	last_node = lstlast(*list);
	current = *list;
	while (current->next->next != NULL)
		current = current->next;
	current->next = NULL;
	last_node->next = *list;
	*list = last_node;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}
