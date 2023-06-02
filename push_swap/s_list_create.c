/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:58:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/02 20:03:09 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makelist(int argc, char **argv, t_node **list)
{
	*list = NULL;
	create_list(list, argc, argv);
	if (!ft_duplicates(*list))
		return ;
	if (lstsize(*list) < 2)
		return ;
	ft_putstr_fd(ERROR, 1);
	exit(1);
}

int	ft_duplicates(t_node *list)
{
	t_node	*temp;

	if (!list)
		return (0);
	while (list->next != NULL)
	{
		temp = list->next;
		while (temp != NULL)
		{
			if (list->x == temp->x)
				return (1);
			temp = temp->next;
		}
		list = list->next;
	}
	return (0);
}
