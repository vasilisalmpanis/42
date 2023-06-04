/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:01:28 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/04 15:38:21 by valmpani         ###   ########.fr       */
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

void	sa(t_node **a, bool value)
{
	swap(a);
	if (value)
		return ;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b, bool value)
{
	swap(b);
	if (value)
		return ;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **a, t_node **b)
{
	sa(a, true);
	sb(b, true);
	ft_putstr_fd("ss\n", 1);
}
