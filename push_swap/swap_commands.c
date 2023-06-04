/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:01:28 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/03 12:02:46 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_node **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}
