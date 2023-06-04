/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:03:41 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/03 12:53:37 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **list)
{
	t_node	*current;
	t_node	*last_node;

	if (list == NULL || *list == NULL)
		return ;
	last_node = lstlast(*list);
	current = *list;
	*list = current->next;
	lstlast(current)->next = current;
	current->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}
