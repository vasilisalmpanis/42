/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:47:17 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 14:12:18 by valmpani         ###   ########.fr       */
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