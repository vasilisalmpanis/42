/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:06:44 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/07 09:34:15 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Connects last element to head and points second to last element to NULL*/
void	reverse_rotate(t_node **list)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = lstlast(*list);
	before_tail = get_stack_before_bottom(*list);
	tmp = *list;
	*list = tail;
	(*list)->next = tmp;
	before_tail->next = NULL;
}

t_node	*get_stack_before_bottom(t_node *list)
{
	while (list && list->next && list->next->next != NULL)
		list = list->next;
	return (list);
}

/*Reverse rotates list a*/
void	rra(t_node **a, bool value)
{
	reverse_rotate(a);
	if (value)
		return ;
	ft_putstr_fd("rra\n", 1);
}

/*Reverse rotates list b*/
void	rrb(t_node **b, bool value)
{
	reverse_rotate(b);
	if (value)
		return ;
	ft_putstr_fd("rrb\n", 1);
}

/*Reverse rotates both lists*/
void	rrr(t_node **a, t_node **b)
{
	rra(a, true);
	rrb(b, true);
	ft_putstr_fd("rrr\n", 1);
}
