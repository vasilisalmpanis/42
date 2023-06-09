/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:03:41 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/07 09:35:52 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Points last node to first, sets head to second node and previous head points
to NULL*/
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

/*Rotates list a*/
void	ra(t_node **a, bool value)
{
	rotate(a);
	if (value)
		return ;
	ft_putstr_fd("ra\n", 1);
}

/*Rotates list b*/
void	rb(t_node **b, bool value)
{
	rotate(b);
	if (value)
		return ;
	ft_putstr_fd("rb\n", 1);
}

/*Rotates both lists*/
void	rr(t_node **a, t_node **b)
{
	ra(a, true);
	rb(b, true);
	ft_putstr_fd("rr\n", 1);
}
