/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:58:13 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/02 10:43:51 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_makelist(int argc, char **argv)
{
	t_node	*list;

	list = NULL;
	create_list(&list, argc, argv);
	if (lstsize(list) <= 2)
		return ;
	if (!ft_duplicates(list))
		ft_putstr_fd(ERROR, 1);
	else
		printf("Okay go ahead");
	lstiter(list);
	dealloc_list(&list);
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
				return (0);
			temp = temp->next;
		}
		list = list->next;
	}
	return (1);
}
