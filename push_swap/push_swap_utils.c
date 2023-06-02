/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:47:17 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/02 21:08:49 by valmpani         ###   ########.fr       */
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

void	swap(t_node **list)
{
	t_node	*current;
	t_node	*next;

	if (*list == NULL || *list == NULL)
		return ;
	current = *list;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*list = next;
}

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
